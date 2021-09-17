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
#include <cmath>

namespace magiUI {
class ImageDrawer : public QThread {
    Q_OBJECT

    size_t s;

    void drawState(QPainter &painter) {
        painter.save();
        std::stringstream ss;
        ss << std::setprecision(2) << std::fixed;
        if (!keyMode) ss << "#";
        ss << "(" << std::setw(5) << mPos.x << ", " << std::setw(5) << mPos.y << ")" << "    ";
        ss << "Time: " << std::setw(10) << Timer::get() << "    ";
        ss << "Size: " << std::setw(10) << s << "    ";
        ss << "drawFPS: " << std::setw(10) << drawFps << "    ";
        ss << "checkFPS: " << std::setw(10) << checkFps << "    ";
        ss << "mainFPS: " << std::setw(10) << mainFps << "    ";
        ss << "audioFPS: " << std::setw(10) << audioFps << "    ";
        if (audioInfo.size()) ss << "audioSize: " << std::setw(10) << audioInfo[0].size() << "     ";
        ss << "Life: " << cLife << " / " << stage->character.lifeBase << "    ";
//        ss << "Key: [";
//        for (auto kv : keyDown)
//            if (kv.second) ss << kv.first << ",";
//        ss << "]    ";
        painter.setFont(QFont("苹方 常规", 10));
        painter.setPen(VColor(Color("3fa7d6")));
        painter.drawText(10, 30, QString::fromStdString(ss.str()));
        painter.restore();
    }

    void drawBullets(QPainter &painter) {
        painter.save();
        std::shared_ptr<Bullets> bullets = stage->getBullet();
        s = bullets->size();
        for (size_t i = 0; i < s; i++) {
            Point p = (*bullets)[i];
            auto pos = p.pos * scale + center;
            if (!pos.inRect(Vec2(-p.r), widget + Vec2(p.r)) || !stage->visible(p)) continue;
            int r = p.r * scale;
            painter.setPen(VColor(p.c));
            painter.setBrush(VColor(p.c));
            painter.drawEllipse(VPoint(pos), r, r);
            // std::cout << p.id << std::endl;
        }
        painter.restore();
    }

    void drawCharacter(QPainter &painter) {
        painter.save();
        // 角色图片
        painter.setPen(Qt::PenStyle::NoPen);
        if (cPic) {
            const double t = 20. / std::max(cPic->width(), cPic->height());
            const Vec2 usize = Vec2(cPic->width(), cPic->height()) * t;
            painter.drawImage(
                        VRect((cPos - usize + stage->character.picOffset) * scale + center,
                              (cPos + usize + stage->character.picOffset) * scale + center),
                        *cPic);
        }
        // 判定点
        auto c = stage->character.pointColor;
        painter.setPen(QPen(VColor(c), 3));
        c.a *= .5;
        painter.setBrush(VColor(c));
        int r = cR * scale;
        painter.drawEllipse(VPoint(cPos * scale + center), r, r);

        painter.restore();
    }

    void drawUI(QPainter &painter) {
        // 血量条
        painter.save();
        painter.setPen(QPen(VColor(Color("d90429a0")), 2));
        double width = 2.5, ly = 225,
               life = 50. * cLife / stage->character.lifeBase;
        Vec2 lp(-life, ly - width), rp(life, ly + width);
        painter.drawRoundedRect(VRect(Vec2(-50, ly - width) * scale + center, Vec2(50, ly + width) * scale + center),
                                width * scale, width * scale);
        painter.setBrush(VColor(Color("ef233ca0")));
        painter.setPen(Qt::PenStyle::NoPen);
        painter.drawRoundedRect(VRect(lp * scale + center, rp * scale + center), width * scale, width * scale);
        painter.restore();
    }

    void drawCQT(QPainter &painter) {
        auto info = audioFreq();
        if (info.size() == 0) return;
        painter.save();
        painter.setPen(Qt::PenStyle::NoPen);
        painter.setBrush(VColor(Color("e92c2450")));
        double w = rSize.x / info.size();
        for (auto i = 0ull; i < info.size(); i++) {
            double start = -rSize.x / 2 + i * w;
            Vec2 lt(start, rSize.y / 2 - std::min(1.f, std::max(.0f, info[i] - 1500) / 500) * rSize.y / 2), rb(start + w, rSize.y / 2);
            painter.drawRect(VRect(lt * scale + center, rb * scale + center));
        }
        painter.restore();
    }

    void drawPixmap(QPixmap &pixmap) {
        pixmap.fill(Qt::transparent);
        QPainter painter(&pixmap);
        // painter.setRenderHint(QPainter::Antialiasing);
        // painter.setRenderHint(QPainter::SmoothPixmapTransform);

//        if (background) {
//            Vec2 bSize(background->width(), background->height());
//            double t = std::max(widget.x / bSize.x,
//                                widget.y / bSize.y);
//            painter.drawImage(VRect(center - bSize * t / 2, center + bSize * t / 2), *background);
//        }

        drawCharacter(painter);
        drawBullets(painter);
        stage->drawEffect(painter);
        drawUI(painter);
        if (debug) drawCQT(painter);
        if (debug) drawState(painter);
    }
public:
    QPixmap buffer, pixmap;
    QMutex bufferLock;

    QTimer *timer;

    ImageDrawer() {}

    void run() {
        timer = new QTimer();
        timer->setInterval(1000 / fps);
        connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()), Qt::DirectConnection);
        timer->start();
        exec();
    }

    // QObject interface
public slots:

    void onTimeout() {
        static time_point<system_clock> last = system_clock::now();
        auto offset = system_clock::now() - last;
        drawFps = 1e9 / duration_cast<nanoseconds>(offset).count();
        last = system_clock::now();

        if (!play) return;

        if (pixmap.size() != VSize(widget))
            pixmap = QPixmap(VSize(widget));

        drawPixmap(pixmap);

        bufferLock.lock();
        buffer.swap(pixmap);
        bufferLock.unlock();
    }
};
}
