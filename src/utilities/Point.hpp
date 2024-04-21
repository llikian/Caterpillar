/******************************************************************************************************
 * @file  Point.hpp
 * @brief Declaration of the Point struct
 ******************************************************************************************************/

#pragma once

extern "C" {
#include <SDL2/SDL.h>
}

/**
 * @struct Point
 * @brief
 */
struct Point : public SDL_Point {
    Point();
    Point(int x, int y);
    Point(int scalar);
};