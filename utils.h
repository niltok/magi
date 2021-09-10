#pragma once

#include <QMutex>
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

    extern Vec2 rSize;

    extern Stage *stage;

    extern double fps, mainFps, drawFps, checkFps;
    extern std::map<int, bool> keyDown;

    extern Vec2 widget, center;
    extern double scale;

    extern double cR;
    extern Vec2 cPos;
    extern size_t cLife;

    extern bool debug, play;

    extern QMediaPlayer *player;

    extern time_point<system_clock> dura;

    extern std::shared_ptr<QImage> cPic, background;

    extern QPoint VPoint(Vec2 p);
    extern QRect VRect(Vec2 lr, Vec2 rb);
    extern QColor VColor(Color c);
    extern QSize VSize(Vec2 s);
}
