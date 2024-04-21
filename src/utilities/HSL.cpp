/******************************************************************************************************
 * @file  HSL.cpp
 * @brief Implementation of the HSL class
 ******************************************************************************************************/

#include "HSL.hpp"

HSL::HSL() : h(), s(100), l(50) {}

HSL::HSL(unsigned short hue, unsigned short saturation, unsigned short light) : h(hue), s(saturation), l(light) { }

HSL::HSL(unsigned short hue) : h(hue), s(100), l(50) { }

Color HSL::toRGBA() const {
    unsigned short hue = (h / 60) % 6;
    float saturation = static_cast<float>(s) / 100.0f;
    float light = static_cast<float>(l) / 100.0f;

    float chroma = saturation * (1.0f - fabsf(2.0f * light - 1.0f));
    float x = chroma * (1.0f - fabsf(static_cast<float>(fmodf(static_cast<float>(hue) / 60.0f, 2.0f)) - 1.0f));
    float m = light - chroma / 2.0f;

    float r, g, b;

    switch(hue) {
        case 0:
            r = chroma;
            g = x;
            b = 0;
            break;
        case 1:
            r = x;
            g = chroma;
            b = 0;
            break;
        case 2:
            r = 0;
            g = chroma;
            b = x;
            break;
        case 3:
            r = 0;
            g = x;
            b = chroma;
            break;
        case 4:
            r = x;
            g = 0;
            b = chroma;
            break;
        case 5:
            r = chroma;
            g = 0;
            b = x;
            break;
        default:
            r = g = b = 0;
    }

    return Color(static_cast<Uint8>(255.0f * (r + m)), static_cast<Uint8>(255.0f * (g + m)), static_cast<Uint8>(255.0f * (b + m)));
}

Color HSL::hueToRGBA(unsigned short hue) {
    unsigned short h = (hue / 60) % 6;

    float x = (1.0f - fabsf(static_cast<float>(fmodf(static_cast<float>(hue) / 60.0f, 2.0f)) - 1.0f));

    switch(h) {
        case 0:
            return Color(255, static_cast<Uint8>(255.0f * x), 0);
        case 1:
            return Color(static_cast<Uint8>(255.0f * x), 255, 0);
        case 2:
            return Color(0, 255, static_cast<Uint8>(255.0f * x));
        case 3:
            return Color(0, static_cast<Uint8>(255.0f * x), 255);
        case 4:
            return Color(static_cast<Uint8>(255.0f * x), 0, 255);
        case 5:
            return Color(255, 0, static_cast<Uint8>(255.0f * x));
        default:
            return Color();
    }
}