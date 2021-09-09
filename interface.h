#pragma once

#include <chrono>
#include <memory>
#include <string>
#include <cmath>
#include <vector>
#include <functional>
#include <QString>
#include <QUrl>
#include <QList>
#include <set>

namespace magi {
    typedef unsigned char byte;
    const double PI = std::acos(-1), PI2 = 2 * PI;
    
    struct Color {
        byte r, g, b, a;

        Color(byte r, byte g, byte b, byte a): r(r), g(g), b(b), a(a) {}
        Color(byte r, byte g, byte b): Color(r, g, b, 255) {}
        Color(): Color(0, 0, 0) {}

        Color(std::string s) {
            r = g = b = 0;
            a = 255;
            switch (s.size()) {
            case 3:
                r = fromHex(s[0]) * 17;
                g = fromHex(s[1]) * 17;
                b = fromHex(s[2]) * 17;
                break;
            case 8:
                a = fromHex(s[6]) * 16 + fromHex(s[7]);
            case 6:
                r = fromHex(s[0]) * 16 + fromHex(s[1]);
                g = fromHex(s[2]) * 16 + fromHex(s[3]);
                b = fromHex(s[4]) * 16 + fromHex(s[5]);
                break;
            default:
                break;
            }
        }

        std::string toHexRGBA() {
            return std::string {
                toHex(r / 16),
                toHex(r % 16),
                toHex(g / 16),
                toHex(g % 16),
                toHex(b / 16),
                toHex(b % 16),
                toHex(a % 16),
                toHex(a / 16)
            };
        }

        std::string toHexRGB() {
            return std::string {
                toHex(r / 16),
                toHex(r % 16),
                toHex(g / 16),
                toHex(g % 16),
                toHex(b / 16),
                toHex(b % 16)
            };
        }

        Color operator+(const Color &c) const { return Color(r + c.r, g + c.g, b + c.b, a + c.a); }
        Color operator*(double t) const { return Color(r * t, g * t, b * t); }

        Color mix(const Color &c, double t) const {
            return (*this) * t + c * (1 - t);
        }

        static char toHex(byte c) {
            if (c <= 9) return '0' + c;
            if (c <= 15) return 'A' + c - 10;
            return '?';
        }

        static byte fromHex(char c) {
            if ('0' <= c && c <= '9') return c - '0';
            if ('a' <= c && c <= 'f') return c - 'a' + 10;
            if ('A' <= c && c <= 'F') return c - 'A' + 10;
            return 0;
        }

        static std::vector<Color> fromCoolors(QString s) {
            auto colors = QUrl(s).fileName().split("-");
            std::vector<Color> v(colors.size());
            for (int i = 0; i < colors.size(); i++) {
                v[i] = colors[i].toStdString();
            }
            return v;
        }
    };

    typedef std::vector<Color> ColorPattern;
    ColorPattern &colors(const std::string &name);

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
        bool enable = true;
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
        std::string pic;
        Vec2 picOffset;
        size_t lifeBase;
        Color pointColor;
    };
    
    struct Stage {
        std::string name;
        std::function<std::shared_ptr<Bullets>()> getBullet;
        Character character;
        std::string music;
        long long endTime;

        bool check(Vec2 pos, double r) {
            std::shared_ptr<Bullets> Re = this -> getBullet();
            int size = Re -> size();
            for (int i = 0 ; i < size ; i++){
                if( ((*Re)[i].pos - pos).length() < ((*Re)[i].r + r)
                        && collision.find((*Re)[i].id) == collision.end() ) {
                    collision.insert((*Re)[i].id);
                    return true;
                }
            }
            return false;
        }

        bool visible(const Point &p) {
            return p.enable && collision.find(p.id) == collision.end();
        }

        // 关卡入口
        static std::vector<Stage> stage;

        std::set<size_t> collision{};
    };

    void initBullets();
}
