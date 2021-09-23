#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qpainter.h"
#include <cmath>
#include "interface.h"
#include "utils.h"
#include "qevent.h"
#include "QtMultimedia/QMediaPlayer"
#include <iostream>
#include "QDir"
#include <chrono>
#include <QFontDatabase>
#include <QAudioProbe>
#include "cqt.h"
#include "audioprocesser.h"

using namespace magi;
using namespace std::chrono;

time_point<system_clock> Timer::t;

namespace magiUI{
    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        // std::cout << (size_t)QThread::currentThreadId() << std::endl;
        QFontDatabase::addApplicationFont("resource/font/PingFang Regular.ttf");
        ui->setupUi(this);
        ui->stageView->installEventFilter(this);
        ui->stageView->setMouseTracking(true);
        ui->stagePage->installEventFilter(this);
        ui->views->setCurrentIndex(0);
        for (auto &s : Stage::stage)
            ui->stageChooser->addItem(QString::fromStdString(s.name));
        ui->stageChooser->setCurrentRow(0);
        startTimer(1000 / fps);
        player = new QMediaPlayer(this);
        audio = std::make_shared<AudioProcesser>();
        audio->start();
        probe = new QAudioProbe(this);
        probe->setSource(player);
        connect(probe, SIGNAL(audioBufferProbed(QAudioBuffer)), this, SLOT(onProbe(QAudioBuffer)));
        play = false;
        initBullets();
        drawer = std::make_shared<ImageDrawer>();
        drawer->start();
        checker = std::make_shared<CollisionChecker>();
        checker->start();
    }

    MainWindow::~MainWindow() {
        drawer->quit();
        drawer->wait();
        checker->quit();
        checker->wait();
        audio->quit();
        audio->wait();
        delete ui;
    }

    bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
        if (watched == ui->stageView
                && event->type() == QEvent::Paint) {
            drawer->bufferLock.lock();
            QPainter painter(ui->stageView);
            painter.drawPixmap(0, 0, drawer->buffer);
            drawer->bufferLock.unlock();
            return true;
        }
        if (watched == ui->stagePage
                && event->type() == QEvent::Paint) {
            QPainter painter(ui->stagePage);
            if (background) {
                Vec2 bSize(background->width(), background->height());
                double t = std::max(widget.x / bSize.x,
                                    widget.y / bSize.y);
                painter.drawImage(VRect(center - bSize * t / 2, center + bSize * t / 2), *background);
            }
            return true;
        }
        if (watched == ui->stageView
                && event->type() == QEvent::MouseMove) {
            mPos = (Vec2(dynamic_cast<QMouseEvent*>(event)->x(), dynamic_cast<QMouseEvent*>(event)->y()) - center) / scale;
            keyMode = false;
        }
        return false;
    }

    void MainWindow::timerEvent(QTimerEvent *event) {
        Q_UNUSED(event);
        if (!play) {
            if (ui->views->currentIndex() == 1) {
                ui->views->setCurrentIndex(2);
                auto d = duration_cast<seconds>(system_clock::now() - Timer::t).count();
                ui->finalDisp->setText(
                            QString::fromStdString("Time: " + std::to_string(d) +
                                                   " s\nLife: " + std::to_string(cLife) + " / " +
                                                   std::to_string(stage->character.lifeBase))
                            );
                player->stop();
            }
            return;
        }

        static time_point<system_clock> last = system_clock::now();
        auto offset = system_clock::now() - last;
        mainFps = 1e9 / duration_cast<nanoseconds>(offset).count();
        last = system_clock::now();

        {
            double time = duration_cast<milliseconds>(offset).count() / 1000.;
            int step = 50;
            if (keyDown[74]) step += 50;
            if (keyDown[75]) step += 100;
            int mover[4][3] = {
                {87, 0, -step}, // 上(W)
                {83, 0, step},  // 下(S)
                {68, step, 0},  // 右(D)
                {65, -step, 0}  // 左(A)
            };
            for (int i = 0; i < 4; i++) {
                auto iter = keyDown.find(mover[i][0]);
                if (iter != keyDown.end() && iter->second)
                    cPos += Vec2(mover[i][1], mover[i][2]) * time;
            }
            if (!keyMode) {
                auto delta = mPos - cPos;
                auto speed = std::min(200., delta.length() * 50);
                if (debug) speed = delta.length() * 30;
                if (delta.length() > 3)
                    cPos += delta.norm() * speed * time;
            }
            cPos = cPos.max(-rSize / 2).min(rSize / 2);
        }
        ui->stageView->update();
    }

    void MainWindow::keyPressEvent(QKeyEvent *event) {
        if (event->isAutoRepeat()) return;
        keyMode = true;
        keyDown[event->key()] = true;
        if (event->key() == 32) {
            collisionLock.lockForWrite();
            collision.clear();
            collisionLock.unlock();
            stage = std::make_shared<Stage>(Stage::stage[ui->stageChooser->currentRow()]);
            Timer::reset();
        }
        if (event->key() == 16777216) {
            play = false;
        }
    }

    void MainWindow::keyReleaseEvent(QKeyEvent *event) {
        if (event->isAutoRepeat()) return;
        keyDown[event->key()] = false;
    }

    void stateReset() {
        cPos = stage->character.startPos;
        cLife = stage->character.lifeBase;
        if (stage->character.pic != "") {
            cPic = std::make_shared<QImage>(QString::fromStdString("resource/image/" + stage->character.pic));
        } else cPic = nullptr;
        if (stage->background != "") {
            background = std::make_shared<QImage>(QString::fromStdString("resource/image/" + stage->background));
        } else background = nullptr;
        collisionLock.lockForWrite();
        collision.clear();
        collisionLock.unlock();
        player->stop();
        audioRawLock.lock();
        audioRaw.clear();
        audioRawLock.unlock();
        audioInfoLock.lock();
        audioInfo.clear();
        audioInfoLock.unlock();
        if (stage->music != "") {
            player->setMedia(QUrl::fromLocalFile(QString::fromStdString("resource/music/" + stage->music)));
            player->play();
        }
        Timer::reset();
        keyMode = true;
        play = true;
    }

    void MainWindow::on_startGameButton_clicked() {
        stage = std::make_shared<Stage>(Stage::stage[ui->stageChooser->currentRow()]);
        debug = ui->debugBox->checkState() == Qt::CheckState::Checked;
        stateReset();
        ui->views->setCurrentIndex(1);
    }

    void MainWindow::resizeEvent(QResizeEvent *event) {
        Q_UNUSED(event);
        widget = Vec2(width(), height());
        scale = std::min((widget.x - 24) / rSize.x,
                         (widget.y - 40) / rSize.y);
        center = widget / 2;
    }

    void MainWindow::on_againButton_clicked() {
        stage = std::make_shared<Stage>(Stage::stage[ui->stageChooser->currentRow()]);
        stateReset();
        ui->views->setCurrentIndex(1);
    }

    void MainWindow::on_backButton_clicked() {
        stage = nullptr;
        ui->views->setCurrentIndex(0);
    }

    void MainWindow::onProbe(const QAudioBuffer &buffer) {
        auto raw = buffer.constData<quint16>();
        auto size = buffer.sampleCount();
        std::vector<float> vbuf(size);
        for(int i = 0; i < size; i++)
            vbuf[i] = raw[i];
        audioRawLock.lock();
        audioRate = buffer.format().sampleRate();
        audioRaw.swap(vbuf);
        audioRawLock.unlock();
    }
}



