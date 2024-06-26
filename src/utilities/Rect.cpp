/******************************************************************************************************
 * @file  Rect.cpp
 * @brief Implementation of the Rect class
 ******************************************************************************************************/

#include "Rect.hpp"

Rect::Rect() : SDL_Rect(0, 0, 0, 0) { }

Rect::Rect(int x, int y, int w, int h) : SDL_Rect(x, y, w, h) { }