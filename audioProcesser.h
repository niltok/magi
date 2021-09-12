#pragma once

#include "utils.h"
#include "interface.h"
#include <QApplication>
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QTimer>
#include "cqt.h"

namespace magiUI {
class AudioProcesser : public QThread {
    Q_OBJECT

public:

    AudioProcesser() {}

    QTimer *timer;

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
        audioFps = 1e9 / duration_cast<nanoseconds>(offset).count();
        last = system_clock::now();

        if (!play) return;

        audioRawLock.lock();
        auto vbuf = audioRaw;
        auto rate = audioRate;
        audioRawLock.unlock();

        if (vbuf.empty()) return;
        auto res = CQT::cqt(vbuf, "hamming", rate, 12 * 3, 12 * 3, 20, 261.63, 20);

        audioInfoLock.lock();
        audioInfo.swap(res);
        audioInfoLock.unlock();
    }
};
}
