#include "effects.h"
#include <QPainter>
#include "utils.h"
#include "interface.h"
#include <vector>
#include <iostream>

namespace magiUI {
using namespace magi;

const Vec2 border(5);

void paintBorder(QPainter &painter, std::function<void(QPainter&)> drawer) {
    painter.save();
    // 让我想起了写 Cubical Type Theory 中的代码的时光
    //
    // left : i = 0, j = 0
    // top : i = 0, j = 1
    // bot : i = 1, j = 0
    // right : i = 1, j = 1
    //
    // ((box[a].x, box[b].y), (box[c].x, box[d].y))
    // a = 0 : top bot left
    // a = 1 : right
    // b = 0 : left top right
    // b = 1 : bot
    // c = 0 : left
    // c = 1 : top bot right
    // d = 0 : top
    // d = 1 : left bot right
    Vec2 box[] = {-rSize / 2, rSize / 2};
    QRegion region;
    for (size_t i = 0; i < 2; i++) for (size_t j = 0; j < 2; j++)
        region += VRect((Vec2(box[i && j].x, box[i && !j].y) - border) * scale + center,
                        (Vec2(box[i || j].x, box[i || !j].y) + border) * scale + center);
    painter.setClipRegion(region);
    drawer(painter);
    painter.restore();
}

void EVALines(QPainter &painter) {
    painter.save();
    long long interval = 5000;
    double width = 10;
    double delta = (magi::Timer::get() % interval) * width / interval * 2;
    painter.setPen(QPen(VColor(Color("d72638")), width * scale));
    for (int i = -rSize.y / width; i <= rSize.y / width; i += 2) {
        painter.drawLine(VPoint(Vec2(-rSize.x * 2, i * width + delta).rotate(-PI / 4) * scale + center),
                         VPoint(Vec2(rSize.x * 2, i * width + delta).rotate(-PI / 4) * scale + center));
    }
    painter.restore();
}

void EVAEffects(QPainter &painter) {
    paintBorder(painter, EVALines);
}

void drawTreeRecursive(QPainterPath &path, size_t index, Vec2 pos, Vec2 direction, double angle, std::function<double(size_t, size_t)> rand) {
    // double nextAngle = PI * (1 - std::exp(-(angle * (1 + rand()))));
    if (index > (1ull << 8) || abs(angle) >= PI) return;
    auto nextDirection = direction.rotate(angle);
    path.moveTo(VPoint(pos * scale + center));
    path.quadTo(VPoint((pos + direction) * scale + center),
                VPoint((pos + direction + nextDirection) * scale + center));
    drawTreeRecursive(path, index * 2, pos + direction + nextDirection, nextDirection.addLen(-10 * rand(index, 0)), angle, rand);
    auto nAngle = -angle * rand(index, 2);
    drawTreeRecursive(path, index * 2 + 1, pos, direction.rotate(nAngle) * std::exp(rand(index, 2) * 2 - 1), nAngle, rand);
}

void drawSpin(QPainterPath &path, size_t deep, Vec2 pos, Vec2 direction, double angle, double step) {
    if (deep == 0) return;
    path.moveTo(VPoint(pos * scale + center));
    auto next = direction.rotate(angle);
    path.quadTo(VPoint((pos + direction) * scale + center), VPoint((pos + direction + next) * scale + center));
    drawSpin(path, deep - 1, pos + direction + next, next.addLen(step), angle, step);
}

void drawSpin(QPainterPath &path, Vec2 pos, double radius, double angle, double len) {
    double division = PI / 4, times = len / division;
    drawSpin(path, times, pos, Vec2(1e-6, 0).rotate(angle), division, std::tan(division / 2) * radius / times);
}
struct ChinaEffectsType {
    size_t count = 0, top = 0;

    void reflLine(QPainterPath &box, Vec2 a, Vec2 b) {
        int d[] = {1, -1};
        for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        // std::cout <<  b.x * d[i] << " " << b.y * d[j] << std::endl,
        box.moveTo(VPoint(Vec2(a.x * d[i], a.y * d[j]) * scale + center)),
        box.lineTo(VPoint(Vec2(b.x * d[i], b.y * d[j]) * scale + center));
    }

    Vec2 nextP(size_t n, Vec2 p) {
        // ^ | < <
        // ^ < > ^
        // > | ^ <
        // ^ > > ^
        // ^
        static const Vec2 top(0, 2), bot(0, -2), left(2, 0), right(-2, 0);
        static const Vec2 table[] = {
            top, right, bot, right, right, top, left, top, right, top, left, left, bot, left, top, top
        };
        return p + table[n];
    }

    void ChinaPattern(QPainter &painter) {
        painter.save();
        painter.setPen(QPen(VColor(Color("0557D0a0")), 1 * scale, Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin));

        auto freq = audioFreq();
        for (auto & i : freq) i = std::min(1.f, std::max(.0f, i - 1500) / 500);
        auto mf = 0.f;
        for (auto i : freq) mf = std::max(mf, i);

        //    auto rand = [&freq](size_t x, size_t y) -> double {
        //        double z = x * y * 25865.3498 + x * x * 1989875.237 + y * y * y * 887646.76 + y * 237868.98 + 70, res = 0;
        //        size_t len = freq.size();
        //        for (size_t i = 0; i < len; i++)
        //            res += (i + 1) * freq[i];
        //        res = std::sin(res + z) / 2 + .5;
        //        return res;
        //    };

        //    auto mod = [] (double x, double m) { return x - (long long)(x / m) * m; };

        //    QPainterPath path;
        //    auto time = Timer::get() / 500.;
        //    if (freq.size())
        //    for (double i = -rSize.x / 2 + 30; i < rSize.x / 2; i += 30) {
        //        drawSpin(path, Vec2(i, -rSize.y / 2 + 7.5), 7.5 * freq[(i + rSize.x / 2) / rSize.x / 2 * freq.size()] + 7.5, PI2 - mod(time + i, PI2), 3 * PI2);
        //        drawSpin(path, Vec2(i, rSize.y / 2 - 7.5), 7.5 * freq[((i + rSize.x / 2) / rSize.x / 2 + .5) * freq.size()] + 7.5, PI2 - mod(time + i + 15, PI2), 3 * PI2);
        //    }
        //    painter.drawPath(path);


        QPainterPath box;

        if (mf == 1) {
            if (!top) {
                count++, top = !top;
                std::cout << count << std::endl;
            }
        } else if (top) top = !top;

        Vec2 current {rSize.x / 2 + 3, 1};
        reflLine(box, Vec2(rSize.x / 2 + 3, 0), Vec2(rSize.x / 2 + 3, 1));
        for (size_t i = 0; i < std::min(500ull, count); i++) {
            auto next = nextP(i % 16, current);
            reflLine(box, current, next);
            current = next;
        }

        painter.drawPath(box);

        painter.restore();
    }

    void operator()(QPainter &painter) {
        ChinaPattern(painter);
        QRadialGradient radial(VPoint(widget / 2), (widget / 2).length());
        radial.setColorAt(.5, Qt::GlobalColor::transparent);
        radial.setColorAt(1, VColor("4361ee80"));
        painter.fillRect(VRect(Vec2(), widget), QBrush(radial));
    }
};

std::function<void(QPainter&)> ChinaEffects = ChinaEffectsType();

void normalBorder(QPainter &painter) {
    painter.save();
    painter.setPen(QPen(VColor(Color("212529a0")), 1 * scale));
    painter.drawRect(VRect(-0.5 * rSize * scale + center,
                           0.5 * rSize * scale + center));
    painter.restore();
}
}
