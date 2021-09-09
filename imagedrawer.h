#pragma once

#include "utils.h"
#include "interface.h"
#include <QApplication>
#include <QThread>
#include <QDebug>
#include <QPixmap>
#include <QMutex>
#include <string>
#include <sstream>
#include <iomanip>
#include <QTimer>
#include <iostream>

namespace magiUI {
class ImageDrawer : public QThread {
    Q_OBJECT

    size_t s;

    void drawState(QPainter &painter) {
        painter.save();
        std::stringstream ss;
        ss << std::setprecision(2) << std::fixed;
        ss << "Time: " << Timer::get() << "    ";
        ss << "Size: " << s << "    ";
        ss << "drawFPS: " << std::setw(7) << drawFps << "    ";
        ss << "mainFPS: " << std::setw(7) << mainFps << "    ";
        ss << "Life: " << cLife << " / " << stage->character.lifeBase << "    ";
//        ss << "Key: [";
//        for (auto kv : keyDown)
//            if (kv.second) ss << kv.first << ",";
//        ss << "]    ";
        QFont font;
        font.setPointSize(10);
        painter.setFont(font);
        painter.drawText(10, 30, QString::fromStdString(ss.str()));
        painter.restore();
    }

    void drawBorder(QPainter &painter) {
        painter.save();
        //painter.setBrush(QColor(255, 160, 90));
        painter.drawRect(VRect(-0.5 * rSize * scale + center,
                               0.5 * rSize * scale + center));
        painter.restore();
    }

    void drawBullets(QPainter &painter) {
        painter.save();
        std::shared_ptr<Bullets> bullets = stage->getBullet();
        s = bullets->size();
        for (size_t i = 0; i < s; i++) {
            Point p = (*bullets)[i];
            if (!stage->visible(p)) continue;
            int r = p.r * scale;
            painter.setPen(VColor(p.c));
            painter.setBrush(VColor(p.c));
            painter.drawEllipse(VPoint(p.pos * scale + center), r, r);
            // std::cout << p.id << std::endl;
        }
        painter.restore();
    }

    void drawCharacter(QPainter &painter) {
        painter.save();
        const int usize = 20;
        if (cPic) {
            painter.drawImage(
                        VRect((cPos - Vec2(usize) + stage->character.picOffset) * scale + center,
                              (cPos + Vec2(usize) + stage->character.picOffset) * scale + center),
                        *cPic, cPic->rect());
        }
        auto c = stage->character.pointColor;
        painter.setPen(QPen(VColor(c), 3));
        painter.setBrush(QColor(c.r, c.g, c.b, c.a * .75));
        int r = cR * scale;
        painter.drawEllipse(VPoint(cPos * scale + center), r, r);
        painter.restore();
    }

    void drawPixmap(QPixmap &pixmap) {
        QPainter painter(&pixmap);
        painter.fillRect(pixmap.rect(), VColor(Color("f8f9fa")));
        drawBorder(painter);
        drawCharacter(painter);
        drawBullets(painter);
        drawState(painter);
    }
public:
    QPixmap buffer;
    QMutex bufferLock;

    QTimer *timer;

    ImageDrawer() {}

    void run() {
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()), Qt::DirectConnection);
        timer->start();
        exec();
    }

    // QObject interface
public slots:

    void onTimeout() {

        if (!play) return;

        QPixmap pixmap(VSize(widget));

        drawPixmap(pixmap);

        bufferLock.lock();
        buffer.swap(pixmap);
        bufferLock.unlock();

        bool collision = stage->check(cPos, cR);
        if (!debug && collision || Timer::get() > stage->endTime)
            if (--cLife == 0) {
                play = false;
            }
    }
};
}