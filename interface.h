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
#include <QReadWriteLock>
#include <QPainter>

namespace magi {
    extern std::set<size_t> collision;
    extern QReadWriteLock collisionLock;
    typedef unsigned char byte;
    const double PI = std::acos(-1), PI2 = 2 * PI;
    
    struct Color {
        double r, g, b, a;

        Color(double r, double g, double b, double a): r(r), g(g), b(b), a(a) {}
        Color(double r, double g, double b): Color(r, g, b, 1.) {}
        Color(int r, int g, int b, int a): r(r / 255.), g(g / 255.), b(b / 255.), a(a / 255.) {}
        Color(int r, int g, int b): Color(r, g, b, 255) {}
        Color(): Color(0., 0., 0.) {}

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
            r /= 255, g /= 255, b /= 255, a /= 255;
        }

        std::string toHexRGBA() {
            int r = this->r * 255,
                g = this->g * 255,
                b = this->b * 255,
                a = this->a * 255;
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
            int r = this->r * 255,
                g = this->g * 255,
                b = this->b * 255;
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
        Color operator*(double t) const { return Color(r * t, g * t, b * t, a * t); }

        Color mix(const Color &c, double t) const {
            return (*this) * (1 - t) + c * t;
        }

        static char toHex(int c) {
            if (c <= 9) return '0' + c;
            if (c <= 15) return 'A' + c - 10;
            return '?';
        }

        static int fromHex(char c) {
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

        double operator[](size_t index) { return index ? y : x; }

        double length() const { return std::sqrt(x * x + y * y); }
        Vec2 abs() const { return Vec2 {std::abs(x), std::abs(y)}; }
        Vec2 norm() const { return (*this) / length(); }
        Vec2 addLen(double t) const { return norm() * (length() + t); }
        Vec2 rotate(double angle) const {
            return Vec2 { x * std::cos(angle) - y * std::sin(angle),
                          x * std::sin(angle) + y * std::cos(angle) };
        }
        Vec2 max(const Vec2 &v) const {
            return Vec2 {std::max(x, v.x), std::max(y, v.y)};
        }
        Vec2 min(const Vec2 &v) const {
            return Vec2 {std::min(x, v.x), std::min(y, v.y)};
        }

        bool inRect(const Vec2 &lt, const Vec2 &rb) const {
            return lt.x < x && x < rb.x && lt.y < y && y < rb.y;
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
        std::string background;
        std::function<void(QPainter&)> drawEffect = emptyEffect;

        bool check(Vec2 pos, double r) {
            bool res = false;
            std::shared_ptr<Bullets> Re = this -> getBullet();
            int size = Re -> size();
            for (int i = 0 ; i < size ; i++){
                if( ((*Re)[i].pos - pos).length() < ((*Re)[i].r + r)) {
                    collisionLock.lockForRead();
                    auto exist = collision.find((*Re)[i].id) != collision.end();
                    collisionLock.unlock();
                    if (exist) continue;
                    collisionLock.lockForWrite();
                    collision.insert((*Re)[i].id);
                    collisionLock.unlock();
                    res = true;
                }
            }
            return res;
        }

        bool visible(const Point &p) {
            if (!p.enable) return false;
            collisionLock.lockForRead();
            auto res = collision.find(p.id) == collision.end();
            collisionLock.unlock();
            return res;
        }

        // 关卡入口
        static std::vector<Stage> stage;

        static void emptyEffect(QPainter&) {}
    };

    void initBullets();

    std::vector<float> audioFreq();
}
