#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qpainter.h"
#include <cmath>
#include "interface.hpp"
#include "qevent.h"

using namespace magi;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stageView->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QPoint VPoint(Vec2 p) {
    return QPoint(p.x, p.y);
}

QRect VRect(Vec2 lr, Vec2 rb) {
    return QRect(VPoint(lr), VPoint(rb));
}

void drawStage(QWidget *stage) {
    QPainter painter(stage);
    Vec2 widget(stage->geometry().width(),
                stage->geometry().height());
    double t = std::min(widget.x / 3.0,
                        widget.y / 5.0);
    Vec2 center = widget / 2;
    { // 画边线
        painter.setBrush(QColor(255, 160, 90));
        painter.drawRect(VRect(Vec2(-1.5, -2.5) * t + center,
                               Vec2(1.5, 2.5) * t + center));
    }
}
bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
    if (watched == ui->stageView
            && event->type() == QEvent::Paint) {
        drawStage(ui->stageView);
        return true;
    }
    if (watched == ui->stageView
            && event->type() == QEvent::KeyPress
            && dynamic_cast<QKeyEvent*>(event)->key() == 32) {
        Timer::reset();
        return true;
    }
    return false;
}
