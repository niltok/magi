#pragma once

#include <QMutex>
#include "qpainter.h"
#include <cmath>
#include "interface.h"
#include <memory>
#include <map>
#include <chrono>
#include "QtMultimedia/QMediaPlayer"
#include <QAudioProbe>

using namespace magi;

namespace magiUI {
    using namespace std::chrono;

    extern Vec2 rSize;

    extern std::shared_ptr<Stage> stage;

    extern double fps, mainFps, drawFps, checkFps, audioFps;
    extern std::map<int, bool> keyDown;

    extern Vec2 widget, center;
    extern double scale;

    extern double cR;
    extern Vec2 cPos;
    extern size_t cLife;

    extern bool debug, play;

    extern QMediaPlayer *player;
    extern QAudioProbe *probe;

    extern time_point<system_clock> dura;

    extern std::shared_ptr<QImage> cPic, background;

    extern long long audioBlock;
    extern int audioRate;
    extern std::vector<float> audioRaw;
    extern std::vector<std::vector<float>> audioInfo;
    extern QMutex audioInfoLock, audioRawLock;

    extern QPoint VPoint(Vec2 p);
    extern QRect VRect(Vec2 lr, Vec2 rb);
    extern QColor VColor(Color c);
    extern QColor VColor(const std::string &s);
    extern QSize VSize(Vec2 s);
}
