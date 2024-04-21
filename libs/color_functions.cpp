#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

#include "color_functions.h"

#include <cmath>

Color makeColor(const unsigned char& r, const unsigned char& g, const unsigned char& b) {
    Color c;

    c.r = r;
    c.g = g;
    c.b = b;
    c.a = 255;

    return c;
}

Color makeColor(const unsigned char& r, const unsigned char& g, const unsigned char& b, const unsigned char& a) {
    Color c;

    c.r = r;
    c.g = g;
    c.b = b;
    c.a = a;

    return c;
}

Color operator *(const Color& c, const float& lambda) {
    return makeColor(c.r * lambda, c.g * lambda, c.b * lambda);
}

Color operator *(const float& lambda, const Color& c) {
    return c * lambda;
}

void operator *=(Color& c, const float& lambda) {
    c = c * lambda;
}

Color operator /(const Color& c, const float& lambda) {
    return c * (1.f / lambda);
}

void operator /=(Color& c, const float& lambda) {
    c = c / lambda;
}

Color operator +(const Color& a, const Color& b) {
    return makeColor(a.r + b.r, a.g + b.g, a.b + b.b);
}

void operator +=(Color& a, const Color& b) {
    a = a + b;
}

Color operator -(const Color& a, const Color& b) {
    return makeColor(a.r - b.r, a.g - b.g, a.b - b.b);
}

void operator -=(Color& a, const Color& b) {
    a = a - b;
}

Color colorInterpolation(const Color& a, const Color& b, const float& t) {
    return a * (1 - t) + b * t;
}

Color hsl(const float& h, float s, float l) {
    s /= 100;
    l /= 100;

    float r1, g1, b1;
    float c = s * (1 - std::fabs(2 * l - 1));
    float m = l - c / 2;
    float x = c * (1 - std::fabs(fmod(h / 60, 2) - 1));

    switch((int) h / 60) {
        case 0:
            r1 = c;
            g1 = x;
            b1 = 0;
            break;
        case 1:
            r1 = x;
            g1 = c;
            b1 = 0;
            break;
        case 2:
            r1 = 0;
            g1 = c;
            b1 = x;
            break;
        case 3:
            r1 = 0;
            g1 = x;
            b1 = c;
            break;
        case 4:
            r1 = x;
            g1 = 0;
            b1 = c;
            break;
        case 5:
            r1 = c;
            g1 = 0;
            b1 = x;
            break;
        default:
            r1 = 0;
            g1 = 0;
            b1 = 0;
            break;
    }

    return makeColor(255 * (m + r1), 255 * (m + g1), 255 * (m + b1));
}

#pragma clang diagnostic pop