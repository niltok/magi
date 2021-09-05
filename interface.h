#pragma once

#include <chrono>
#include <memory>
#include <string>
#include <cmath>
#include <vector>
#include <functional>

namespace magi {
    typedef unsigned char byte;
    const double PI = std::acos(-1), PI2 = 2 * PI;
    
    struct Color {
        byte r, g, b, a;

        Color(byte r, byte g, byte b, byte a): r(r), g(g), b(b), a(a) {}
        Color(byte r, byte g, byte b): Color(r, g, b, 255) {}
        Color(): Color(0, 0, 0) {}
    };

    struct Vec2 {
        double x, y;

        Vec2(double x, double y): x(x), y(y) {}
        explicit Vec2(double a): Vec2(a, a) {}
        Vec2(): Vec2(0) {}

        Vec2 operator+(const Vec2 &v) const { return Vec2 {x + v.x, y + v.y}; }
        Vec2 &operator+=(const Vec2 &v) { x += v.x, y += v.y; return *this; }
        Vec2 operator-() const { return Vec2 {-x, -y}; }
        Vec2 operator-(const Vec2 &v) const { return *this + (-v); }
        Vec2 &operator-=(const Vec2 &v) { x -= v.x, y -= v.y; return *this; }
        Vec2 operator*(double s) const { return Vec2 {x * s, y * s}; }
        Vec2 &operator*=(double s) { x *= s, y *= s; return *this; }
        friend Vec2 operator*(double s, const Vec2 &v) { return v * s; }
        Vec2 operator/(double s) const { return Vec2 {x / s, y / s}; }

        double length() const { return std::sqrt(x * x + y * y); }
        Vec2 abs() const { return Vec2 {std::abs(x), std::abs(y)}; }
        Vec2 rotate(double angle) const {
            return Vec2 { x * (std::cos(angle) - std::sin(angle)),
                          y * (std::sin(angle) + std::cos(angle)) };
        }
        Vec2 max(const Vec2 &v) const {
            return Vec2 {std::max(x, v.x), std::max(y, v.y)};
        }
        Vec2 min(const Vec2 &v) const {
            return Vec2 {std::min(x, v.x), std::min(y, v.y)};
        }

        // 点乘
        double dot(Vec2 v) const { return x * v.x + y * v.y; }
        // 叉乘
        double cross(Vec2 v) const { return x * v.y - y * v.x; }
        // 虚数乘
        Vec2 operator*(Vec2 v) const { return Vec2 {cross(v), dot(v)}; }
    };

    struct Point {
        Point () {}
        Point ( long long id , Color c , double r ) : id(id) , c(c) , r(r) {}
        Color c;
        double r; // 半径
        Vec2 pos;
        size_t id;
    };

    // 每次绘制时调用
    struct Bullets {
        // 当前时间所有弹幕数量
        virtual size_t size() const = 0;
        // 每个弹的信息
        virtual Point operator[](size_t index) = 0;
    };

    using namespace std::chrono;
    struct Timer {
        static time_point<system_clock> t;
        // 关卡开始时调用
        static void reset() {
            t = system_clock::now();
        }
        static long long get() {
            return duration_cast<milliseconds>(system_clock::now() - t).count();
        }
    };

    struct Character {
        Vec2 pos;
        double r;
    };
    
    struct Stage {
        std::string name;
        std::function<std::shared_ptr<Bullets>()> getBullet;
        Character character;
        std::string music;

        void check() {
        }

        // 关卡入口
        static std::vector<Stage> stage;
    };
}
