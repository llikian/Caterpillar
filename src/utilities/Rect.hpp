/******************************************************************************************************
 * @file  Rect.hpp
 * @brief Declaration of the Rect struct
 ******************************************************************************************************/

#pragma once

extern "C" {
#include <SDL2/SDL.h>
}

/**
 * @struct Rect
 * @brief Functions as a child of the C like struct SDL_Rect,
 *        in order to add C++ like functionality such as constructors
 *        and methods.
 */
struct Rect : public SDL_Rect {
    /**
     * Default constructor
     */
    Rect();

    /**
     * @brief Constructs a rectangle at coordinates (x ; y) being w pixels wide and h pixels tall
     * @param x The x coordinate of the rectangle
     * @param y The y coordinate of the rectangle
     * @param w The width of the rectangle
     * @param h The height of the rectangle
     */
    Rect(int x, int y, int w, int h);
};