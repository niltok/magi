#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qpainter.h"
#include <cmath>
#include "interface.h"
#include "qevent.h"
#include "handler.h"
#include "QtMultimedia/QMediaPlayer"
#include <iostream>
#include "QDir"
#include <chrono>

using namespace magi;
using namespace std::chrono;

time_point<system_clock> Timer::t;

namespace magiUI{
    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        ui->stageView->installEventFilter(this);
        ui->views->setCurrentIndex(0);
        for (auto s : Stage::stage)
            ui->stageChooser->addItem(QString::fromLocal8Bit(s.name.c_str()));
        ui->stageChooser->setCurrentRow(0);
        startTimer(1000 / fps);
        // std::cout << QDir::current().path().toStdString() << std::endl;
        player = new QMediaPlayer(this);
        // player->setMedia(QUrl("qrc:/music/OdeToJoy1"));
        // player->play();
        play = false;
        initBullets();
    }

    MainWindow::~MainWindow() {
        delete ui;
    }

    bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
        if (watched == ui->stageView
                && event->type() == QEvent::Paint) {
            drawStage(ui->stageView);
            return true;
        }
        return false;
    }

    void MainWindow::timerEvent(QTimerEvent *event) {
        Q_UNUSED(event);
        if (!play) return;
        {
            static time_point<system_clock> last = system_clock::now();
            realFps = 1e9 / duration_cast<nanoseconds>(system_clock::now() - last).count();
            last = system_clock::now();
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
                    cPos += Vec2(mover[i][1], mover[i][2]) / fps;
            }
            cPos = cPos.max(-rSize / 2).min(rSize / 2);
        }
        bool collision = stage->check(cPos, cR);
        if (!debug && collision || Timer::get() > stage->endTime)
            if (--cLife == 0) {
                ui->views->setCurrentIndex(2);
                auto d = duration_cast<seconds>(system_clock::now() - Timer::t).count();
                ui->finalDisp->setText(
                            QString::fromStdString("Time: " + std::to_string(d) +
                            " s\nLife: " + std::to_string(cLife) + " / " + std::to_string(stage->character.lifeBase))
                );
                player->stop();
                play = false;
            }
        update();
    }

    void MainWindow::keyPressEvent(QKeyEvent *event) {
        if (event->isAutoRepeat()) return;
        keyDown[event->key()] = true;
        // setWindowTitle(QString::number(event->key()));
        if (event->key() == 32) {
            stage->collision.clear();
            Timer::reset();
        }
        if (event->key() == 16777216 && play) {
            ui->views->setCurrentIndex(2);
            auto d = duration_cast<seconds>(system_clock::now() - Timer::t).count();
            ui->finalDisp->setText(
                        QString::fromStdString("Time: " + std::to_string(d) +
                        " s\nLife: " + std::to_string(cLife) + " / " + std::to_string(stage->character.lifeBase))
            );
            player->stop();
            play = false;
        }
    }

    void MainWindow::keyReleaseEvent(QKeyEvent *event) {
        if (event->isAutoRepeat()) return;
        keyDown[event->key()] = false;
    }

    void stateReset() {
        Timer::reset();
        cPos = Vec2 { 0, 100 };
        player->stop();
        if (stage->music != "") {
            player->setMedia(QUrl(QString::fromLocal8Bit(stage->music.c_str())));
            player->play();
        }
        play = true;
        cLife = stage->character.lifeBase;
        if (stage->character.pic != "")
            cPic = std::make_shared<QImage>(QString::fromStdString(stage->character.pic));
        stage->collision.clear();
    }

    void MainWindow::on_startGameButton_clicked() {
        stage = &Stage::stage[ui->stageChooser->currentRow()];
        ui->views->setCurrentIndex(1);
        debug = ui->debugBox->checkState() == Qt::CheckState::Checked;
        stateReset();
    }

    void MainWindow::resizeEvent(QResizeEvent *event) {
        Q_UNUSED(event);
        widget = Vec2(width(), height());
        scale = std::min((widget.x - 18) / rSize.x,
                         (widget.y - 30) / rSize.y);
        center = widget / 2;
    }

    void MainWindow::on_againButton_clicked() {
        ui->views->setCurrentIndex(1);
        stateReset();
    }

    void MainWindow::on_backButton_clicked() {
        stage = nullptr;
        ui->views->setCurrentIndex(0);
    }
}


