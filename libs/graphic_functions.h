#ifndef GRAPHIC_FUNCTIONS
#define GRAPHIC_FUNCTIONS

#include <SDL2/SDL.h>
#include <cmath>
#include "color_functions.h"
#include "complex_functions.h"

void setColor(SDL_Renderer* renderer, const Color& color);
SDL_Rect makeRect(const int& x, const int& y, const int& w, const int& h);
void circle(SDL_Renderer* renderer, const Complex& center, const int& radius, const Color& color);
void circleFill(SDL_Renderer* renderer, const Complex& center, const int& radius, const Color& color);
void outlinedCircle(SDL_Renderer* renderer, const Complex& center, const Color& outline, const Color& filling, const int& radius);

#endif