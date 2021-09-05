#pragma once

#include "qpainter.h"
#include <cmath>
#include "interface.h"
#include <memory>

using namespace magi;

namespace magiUI {
    const Vec2 rSize(300, 500);

    Stage stage;

    double cR = 5;
    Vec2 cPos;

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
