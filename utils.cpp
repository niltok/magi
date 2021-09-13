#include <QMutex>
#include "qpainter.h"
#include <cmath>
#include "interface.h"
#include <memory>
#include <complex>
#include <map>
#include <chrono>
#include "QtMultimedia/QMediaPlayer"
#include <QReadWriteLock>
#include <QAudioProbe>
#include <iostream>
#include <cmath>
#include "utils.h"

namespace magi {
using namespace magiUI;
std::set<size_t> collision{};
QReadWriteLock collisionLock;
double pitchFreq(double p) {
    return 440 * pow(2, p / 12);
}
std::vector<double> audioFreq() {
    audioInfoLock.lock();
    //std::vector<double> res(5 * 12);
    std::vector<double> res(audioInfo.size());
    for (size_t i = 0; i< res.size(); i++)
        res[i] = audioInfo[i].length();
    //auto rate = audioRate;
    //auto delta = Timer::get() - audioBlock;
    //if (audioInfo.size())
    //    for (size_t i = 0; i < res.size(); i++)
    //        res[i] = audioInfo[pitchFreq(i - 33) * audioInfo.size() / rate].length();
    audioInfoLock.unlock();
    return res;
}
}

namespace magiUI {
using namespace magi;
using namespace std::chrono;

Vec2 rSize(300, 500);

std::shared_ptr<Stage> stage;

double fps = 100, mainFps, drawFps, checkFps, audioFps;
std::map<int, bool> keyDown;

Vec2 widget, center;
double scale;

double cR = 3;
Vec2 cPos;
size_t cLife;

bool debug, play;

QMediaPlayer *player;
QAudioProbe *probe;

time_point<system_clock> dura;

std::shared_ptr<QImage> cPic, background;

long long audioBlock;
int audioRate;
std::vector<Vec2> audioRaw;
std::vector<Vec2> audioInfo;
QMutex audioInfoLock, audioRawLock;

QPoint VPoint(Vec2 p) {
    return QPoint(p.x, p.y);
}

QRect VRect(Vec2 lr, Vec2 rb) {
    return QRect(VPoint(lr), VPoint(rb));
}

QColor VColor(Color c) {
    return QColor(c.r * 255, c.g * 255, c.b * 255, c.a * 255);
}

QSize VSize(Vec2 s) {
    return QSize(s.x, s.y);
}
}
