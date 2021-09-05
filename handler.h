#pragma once

#include "qwidget.h"
#include "qpainter.h"
#include "utils.h"
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
        ss << "Time: " << Timer::get() << "\t ";
        ss << "Size: " << s << "\t ";
        ss << "Key: ";
        for (auto kv : keyDown)
            if (kv.second) ss << kv.first << " ";
        ss << "\t ";
        QFont font;
        font.setFamily("Microsoft YaHei");
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
        std::shared_ptr<Bullets> bullets = stage.getBullet();
        s = bullets->size();
        for (size_t i = 0; i < s; i++) {
            Point p = (*bullets)[i];
            c = p.c;
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
        painter.setPen(QPen(QColor(230, 57, 70), 2, Qt::PenStyle::DotLine));
        int r = cR * scale;
        painter.drawEllipse(VPoint(cPos * scale + center), r, r);
        painter.restore();
    }

    void drawStage(QWidget *stage) {
        QPainter painter(stage);
        drawBorder(painter);
        drawBullets(painter);
        drawCharacter(painter);
        drawState(painter);
    }
}
