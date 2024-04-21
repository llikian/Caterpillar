/******************************************************************************************************
 * @file  HSL.hpp
 * @brief Declaration of the HSL class
 ******************************************************************************************************/

#pragma once

#include "Color.hpp"

/**
 * @struct HSL
 * @brief Class representing a color using the HSL (Hue, Saturation, Light) format
 */
struct HSL {
    HSL();
    HSL(unsigned short hue, unsigned short saturation, unsigned short light);
    HSL(unsigned short hue);

    unsigned short h; ///< Hue of the color, ranges from 0 to 360
    unsigned short s; ///< Saturation of the color, ranges from 0 to 100
    unsigned short l; ///< Brightness of the color, ranges from 0 to 100

    Color toRGBA() const;

    static Color hueToRGBA(unsigned short hue);
};