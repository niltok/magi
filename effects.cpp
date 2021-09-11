#include "effects.h"
#include <QPainter>
#include "utils.h"
#include "interface.h"

namespace magiUI {
using namespace magi;

void EVALines(QPainter &painter) {
    painter.save();
    long long interval = 5000;
    double width = 10;
    double delta = (magi::Timer::get() % interval) * width / interval * 2;
    painter.setPen(QPen(VColor(Color("d72638")), width * scale));
    for (int i = -rSize.y / width; i < rSize.y / width; i += 2) {
        painter.drawLine(VPoint(Vec2(-rSize.x * 2, i * width + delta).rotate(-PI / 4) * scale + center),
                         VPoint(Vec2(rSize.x * 2, i * width + delta).rotate(-PI / 4) * scale + center));
    }
    painter.restore();
}

void EVAEffects(QPainter &painter) {
    painter.save();
    Vec2 w(5);
    Vec2 lt = -rSize / 2, rb = rSize / 2;
    painter.setClipRect(VRect((lt - w) * scale + center, (Vec2(lt.x, rb.y) + w) * scale + center));
    EVALines(painter);
    painter.setClipRect(VRect((lt - w) * scale + center, (Vec2(rb.x, lt.y) + w) * scale + center));
    EVALines(painter);
    painter.setClipRect(VRect((Vec2(lt.x, rb.y) - w) * scale + center, (rb + w) * scale + center));
    EVALines(painter);
    painter.setClipRect(VRect((Vec2(rb.x, lt.y) - w) * scale + center, (rb + w) * scale + center));
    EVALines(painter);
    painter.restore();
}
}
