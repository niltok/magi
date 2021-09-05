#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qpainter.h"
#include <cmath>
#include "interface.h"
#include "qevent.h"
#include "handler.h"

using namespace magi;

std::chrono::time_point<system_clock> Timer::t;

namespace magiUI{
    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        ui->stageView->installEventFilter(this);
        for (auto s : Stage::stage)
            ui->stageChooser->addItem(QString::fromLocal8Bit(s.name.c_str()));
        ui->stageChooser->setCurrentRow(0);
        startTimer(10);
    }

    MainWindow::~MainWindow()
    {
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
        update();
    }

    void MainWindow::keyPressEvent(QKeyEvent *event) {
        if (event->isAutoRepeat()) return;
        Vec2 widget(width(), height());
        double t = std::min((widget.x - 18) / rSize.x,
                            (widget.y - 30) / rSize.y);
        setWindowTitle(QString::number(event->key()));
        if (event->key() == 32) Timer::reset();
        int step = 1;
        int mover[4][3] = {
            {87, 0, -step}, // 上(W)
            {83, 0, step},  // 下(S)
            {68, step, 0},  // 右(D)
            {65, -step, 0}  // 左(A)
        };
        for (int i = 0; i < 4; i++)
            if (event->key() == mover[i][0])
                cPos += Vec2(mover[i][1], mover[i][2]) * t;
        cPos = cPos.max(-rSize / 2).min(rSize / 2);
        if (event->key() == 16777216 && ui->views->currentIndex() == 1)
            ui->views->setCurrentIndex(0);
    }

    void MainWindow::keyReleaseEvent(QKeyEvent *event) {
        if (event->isAutoRepeat()) return;
    }

    void MainWindow::on_startGameButton_clicked() {
        stage = Stage::stage[ui->stageChooser->currentRow()];
        ui->views->setCurrentIndex(1);
        Timer::reset();
    }
}


