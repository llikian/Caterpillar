/******************************************************************************************************
 * @file  drawColony.hpp
 * @brief Declaration of functions for drawing different things with SDL
 ******************************************************************************************************/

#pragma once

#include <string>
extern "C" {
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
}

#include "Color.hpp"
#include "Point.hpp"
#include "Rect.hpp"
#include "vec2.hpp"

typedef SDL_Texture Texture;
typedef SDL_Surface Surface;

void setColor(SDL_Renderer* renderer, const Color& color);
void setColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void setColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b);

void circle(SDL_Renderer* renderer, const Point& center, const int& radius, const Color& color);
void circleFill(SDL_Renderer* renderer, const Point& center, const int& radius, const Color& color);
void outlinedCircle(SDL_Renderer* renderer, const Point& center, const Color& outline, const Color& filling, const int& radius);

void circle(SDL_Renderer* renderer, const vec2& center, const int& radius, const Color& color);
void circleFill(SDL_Renderer* renderer, const vec2& center, const int& radius, const Color& color);
void outlinedCircle(SDL_Renderer* renderer, const vec2& center, const Color& outline, const Color& filling, const int& radius);