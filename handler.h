#pragma once

#include "qwidget.h"
#include "qpainter.h"
#include "utils.h"
#include <sstream>
#include <string>
#include <memory>
#include <iostream>
#include <iomanip>

namespace magiUI {
    size_t s;

    void drawState(QPainter &painter) {
        painter.save();
        std::stringstream ss;
        ss << std::setprecision(2) << std::fixed;
        ss << "Time: " << Timer::get() << "\t ";
        ss << "Size: " << s << "\t ";
        ss << "FPS: " << realFps << "\t ";
        ss << "Life: " << cLife << "/" << stage->character.lifeBase << "\t ";
        ss << "Key: ";
        for (auto kv : keyDown)
            if (kv.second) ss << kv.first << " ";
        ss << "\t ";
        QFont font;
        font.setPointSize(10);
        painter.setFont(font);
        painter.drawText(10, 30, QString::fromLocal8Bit(ss.str().c_str()));
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

    void drawStage(QWidget *stage) {
        QPainter painter(stage);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        drawBorder(painter);
        drawCharacter(painter);
        drawBullets(painter);
        drawState(painter);
    }
}
