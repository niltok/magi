#pragma once

#include "qpainter.h"
#include <cmath>
#include "interface.h"
#include <memory>
#include <map>
#include <chrono>
#include "QtMultimedia/QMediaPlayer"

using namespace magi;

namespace magiUI {
    using namespace std::chrono;
    const Vec2 rSize(300, 500);

    Stage *stage;

    double fps = 60;
    std::map<int, bool> keyDown;

    Vec2 widget, center;
    double scale;

    double cR = 3;
    Vec2 cPos;
    size_t cLife;

    bool debug, play;

    QMediaPlayer *player;

    time_point<system_clock> dura;

    QPoint VPoint(Vec2 p) {
        return QPoint(p.x, p.y);
    }

    QRect VRect(Vec2 lr, Vec2 rb) {
        return QRect(VPoint(lr), VPoint(rb));
    }

    QColor VColor(Color c) {
        return QColor(c.r, c.g, c.b, c.a);
    }
}
