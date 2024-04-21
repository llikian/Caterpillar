/******************************************************************************************************
 * @file  Color.hpp
 * @brief Declaration of classes related to color
 ******************************************************************************************************/

#pragma once

#include <SDL2/SDL.h>

/**
 * @struct RGB
 * @brief Class representing a color using the RGB (Red, Blue, Green) format
 */
struct RGB {
    Uint8 r; ///< Red component
    Uint8 g;
    Uint8 b;

    RGB();
    RGB(Uint8 r, Uint8 g, Uint8 b);
    RGB(Uint8 value);
};

/**
 * @struct Color
 * @brief Class representing a color using the RGBA (Red, Blue, Green, Alpha) format
 */
struct Color : public SDL_Color {
    Color();
    Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    Color(Uint8 r, Uint8 g, Uint8 b);
    Color(Uint8 value, Uint8 alpha);
    Color(Uint8 value);
    Color(const RGB& color);
};