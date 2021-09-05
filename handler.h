#pragma once

#include "qwidget.h"
#include "qpainter.h"
#include "Utils.h"
#include <sstream>
#include <string>
#include <memory>
#include <iostream>

namespace magiUI {
    size_t s;
    Color c;
    void drawState(QPainter &painter) {
        painter.save();
        std::stringstream ss;
        ss << "Time: " << Timer::get() << "\n ";
        ss << "Size: " << s << "\n ";
        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(10);
        painter.setFont(font);
        painter.drawText(10, 30, QString::fromLocal8Bit(ss.str().c_str()));
        painter.restore();
    }

    void drawBorder(QPainter &painter, double t, Vec2 center) {
        painter.save();
        //painter.setBrush(QColor(255, 160, 90));
        painter.drawRect(VRect(-0.5 * rSize * t + center,
                               0.5 * rSize * t + center));
        painter.restore();
    }

    void drawBullets(QPainter &painter, double t, Vec2 center) {
        painter.save();
        std::shared_ptr<Bullets> bullets = stage->getBullet();
        s = bullets->size();
        for (size_t i = 0; i < s; i++) {
            Point p = (*bullets)[i];
            c = p.c;
            int r = p.r * t;
            painter.setPen(VColor(p.c));
            painter.setBrush(VColor(p.c));
            painter.drawEllipse(VPoint(p.pos * t + center), r, r);
            std::cout << p.id << std::endl;
        }
        painter.restore();
    }

    void drawCharacter(QPainter &painter, double t, Vec2 center) {
        painter.save();
        painter.setPen(QPen(QColor(230, 57, 70), 2, Qt::PenStyle::DotLine));
        int r = stage->character.r * t;
        painter.drawEllipse(VPoint(stage->character.pos * t + center), r, r);
        painter.restore();
    }

    void drawStage(QWidget *stage) {
        QPainter painter(stage);
        Vec2 widget(stage->geometry().width(),
                    stage->geometry().height());
        double t = std::min((widget.x - 18) / rSize.x,
                            (widget.y - 30) / rSize.y);
        Vec2 center = widget / 2;
        drawBorder(painter, t, center);
        drawBullets(painter, t, center);
        drawCharacter(painter, t, center);
        drawState(painter);
    }
}
