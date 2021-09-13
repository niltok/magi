#include "fft.h"

using namespace magi;

typedef std::vector<Vec2>::iterator iter;

void separate(iter s, iter e) {
    size_t n = e - s, h = n / 2;

    static std::vector<Vec2> b;
    if (b.size() < n) b.resize(n);

    for (size_t i = 0; i < n; i++)
        b[i] = s[i];
    for (size_t i = 0; i < h; i++)
        s[i] = b[i * 2];
    for (size_t i = h; i < n; i++)
        s[i] = b[(i - h) * 2 + 1];
}

void fft(iter s, iter e, double d) {
    size_t n = e - s, h = n / 2;
    if (n < 2) return;

    separate(s, e);
    fft(s, s + h, d);
    fft(s + h, e, d);

    for (size_t k = 0; k < h; k++) {
        auto even = s[k];
        auto odd  = s[k + h] * Vec2(0, d * PI2 * k / n).exp();
        s[k]      = even + odd;
        s[k + h]  = even - odd;
    }
}
