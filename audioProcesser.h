#pragma once

#include "utils.h"
#include "interface.h"
#include <QApplication>
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QTimer>
#include "fft.h"

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
        std::vector<Vec2> vbuf;
        vbuf.swap(audioRaw);
        auto rate = audioRate;
        audioRawLock.unlock();

        if (vbuf.empty()) return;

        size_t originSize = vbuf.size(), frame = 5, psize = 1;
        while (psize < vbuf.size()) psize <<= 1;
        vbuf.resize(psize);
//        for (int n = 1; n < frame; n++)
//            for (int i = 0; i < originSize; i++)
//                vbuf[n * originSize + i] = vbuf[i];
        fft(vbuf.begin(), vbuf.end(), -1);
        for (auto &i : vbuf) i /= vbuf.size();
        //auto res = CQT::cqt(vbuf, "hamming", rate, 12 * 3, 12, 100, 130.81, 20);

        audioInfoLock.lock();
        audioInfo.swap(vbuf);
        audioBlock = Timer::get();
        audioInfoLock.unlock();
    }
};
}
