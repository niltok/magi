#pragma once

#include <chrono>
#include <memory>
#include <string>

typedef unsigned char byte;

namespace magi {
    struct Color {
        byte r, g, b, a;

        Color(byte r, byte g, byte b, byte a): r(r), g(g), b(b), a(a) {}
        Color(byte r, byte g, byte b): Color(r, g, b, 255) {}
        Color(): Color(0, 0, 0) {}
    };

    struct Vec2 {
        double x, y;

        Vec2(double x, double y): x(x), y(y) {}
        Vec2(double a): Vec2(a, a) {}
        Vec2(): Vec2(0) {}

        Vec2 operator+(Vec2 v) const { return Vec2 {x + v.x, y + v.y}; }
        Vec2 operator-() const { return Vec2 {-x, -y}; }
        Vec2 operator-(Vec2 v) const { return *this + (-v); }
        Vec2 operator*(double s) const { return Vec2 {x * s, y * s}; }
        friend Vec2 operator*(double s, const Vec2 &v) { return v * s; }
        // 点乘
        double dot(Vec2 v) const { return x * v.x + y * v.y; }
        // 叉乘
        double cross(Vec2 v) const { return x * v.y - y * v.x; }
        // 虚数乘
        Vec2 operator*(Vec2 v) const { return Vec2 {cross(v), dot(v)}; }
    };

    struct Point {
        Color c;
        double r; // 半径
        Vec2 pos;
    };

    // 每次绘制时调用
    struct Bullet {
        // 当前时间所有弹幕数量
        virtual size_t size() const = 0;
        // 每个弹的信息
        virtual Point operator[](size_t index) const = 0;
    };

    namespace Timer {
        using namespace std::chrono;
        time_point<system_clock> t;
        // 关卡开始时调用
        void reset() {
            t = system_clock::now();
        }
        long long get() {
            return duration_cast<milliseconds>(system_clock::now() - t).count();
        }
    };

    struct Character {
        // 键盘/鼠标/触摸 触发
        virtual void move(Vec2 delta) = 0;
        //绘制时调用
        virtual Vec2 pos() const = 0;
    };

    struct Stage {
        std::string name;
        std::shared_ptr<Bullet> bullet;
        std::shared_ptr<Character> character;
        std::shared_ptr<std::string> music;

        // 关卡入口
        static std::shared_ptr<Stage> get(size_t index);
        static size_t size();
    };
}