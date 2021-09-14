#include <QMutex>
#include "qpainter.h"
#include <cmath>
#include "interface.h"
#include <memory>
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
void freqReduce(std::vector<float> &f) {
    size_t len = 12;
    for (size_t l = 0; l < len; l++) {
        for (size_t i = l + l; i < f.size(); i += len)
            f[l] = std::max(f[l], f[i]);
    }
    f.resize(len);
}
std::vector<float> audioFreq() {
    audioInfoLock.lock();
    std::vector<float> res(audioInfo.size());
    auto delta = Timer::get() - audioBlock;
    for (size_t i = 0; i < res.size(); i++)
        res[i] = audioInfo[i][(audioInfo[i].size() - 1) * std::max(0., std::min(1., delta / 100.))];
    audioInfoLock.unlock();
    // freqReduce(res);
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
std::vector<float> audioRaw;
std::vector<std::vector<float>> audioInfo;
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

QColor VColor(const std::string &s) {
    return VColor(Color(s));
}

QSize VSize(Vec2 s) {
    return QSize(s.x, s.y);
}
}
