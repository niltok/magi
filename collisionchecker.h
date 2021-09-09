#pragma once

#include "utils.h"
#include "interface.h"
#include <QApplication>
#include <QThread>
#include <QDebug>
#include <QPixmap>
#include <QMutex>
#include <string>
#include <sstream>
#include <iomanip>
#include <QTimer>

namespace magiUI {
class CollisionChecker : public QThread {
    Q_OBJECT

public:

    QTimer *timer;

    CollisionChecker() {}

    void run() {
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()), Qt::DirectConnection);
        timer->start();
        exec();
    }

    // QObject interface
public slots:

    void onTimeout() {
        static time_point<system_clock> last = system_clock::now();
        auto offset = system_clock::now() - last;
        checkFps = 1e9 / duration_cast<nanoseconds>(offset).count();
        last = system_clock::now();

        if (!play) return;

        bool collision = stage->check(cPos, cR);
        if (!debug && collision || Timer::get() > stage->endTime)
            if (--cLife == 0) {
                play = false;
            }
    }
};
}
