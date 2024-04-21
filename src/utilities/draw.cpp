/******************************************************************************************************
 * @file  drawColony.cpp
 * @brief Definition of functions for drawing different things with SDL
 ******************************************************************************************************/

#include "draw.hpp"

#include <stdexcept>

void setColor(SDL_Renderer* renderer, const Color& color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void setColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void setColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b) {

    SDL_SetRenderDrawColor(renderer, r, g, b, 0);
}

void circle(SDL_Renderer* renderer, const Point& center, const int& radius, const Color& color) {
    int x = 0, y = radius;

    setColor(renderer, color);

    while(x <= y) {
        Point points[8]{Point(x, y),
                        Point(-x, y),
                        Point(x, -y),
                        Point(-x, -y),
                        Point(y, x),
                        Point(-y, x),
                        Point(y, -x),
                        Point(-y, -x)};

        for(Point& point: points) {
            point.x += center.x;
            point.y += center.y;
        }

        SDL_RenderDrawPoints(renderer, points, 8);

        ++x;
        y = sqrt(radius * radius - x * x);
    }
}

void circleFill(SDL_Renderer* renderer, const Point& center, const int& radius, const Color& color) {
    int x = 0, y = radius, a, b, c, d;

    setColor(renderer, color);

    while(x <= radius) {
        a = center.x + x;
        b = center.y + y;
        c = center.x - x;
        d = center.y - y;

        SDL_RenderDrawLine(renderer, a, b, a, d);
        SDL_RenderDrawLine(renderer, c, b, c, d);

        ++x;
        y = sqrt(radius * radius - x * x);
    }
}

void outlinedCircle(SDL_Renderer* renderer, const Point& center, const Color& outline, const Color& filling, const int& radius) {
    circleFill(renderer, center, radius, filling);
    circle(renderer, center, radius, outline);
}


void circle(SDL_Renderer* renderer, const vec2& center, const int& radius, const Color& color) {
    int x = 0, y = radius;

    setColor(renderer, color);

    while(x <= y) {
        Point points[8]{Point(x, y),
                        Point(-x, y),
                        Point(x, -y),
                        Point(-x, -y),
                        Point(y, x),
                        Point(-y, x),
                        Point(y, -x),
                        Point(-y, -x)};

        for(Point& point: points) {
            point.x += center.x;
            point.y += center.y;
        }

        SDL_RenderDrawPoints(renderer, points, 8);

        ++x;
        y = sqrt(radius * radius - x * x);
    }
}

void circleFill(SDL_Renderer* renderer, const vec2& center, const int& radius, const Color& color) {
    int x = 0, y = radius, a, b, c, d;

    setColor(renderer, color);

    while(x <= radius) {
        a = center.x + x;
        b = center.y + y;
        c = center.x - x;
        d = center.y - y;

        SDL_RenderDrawLine(renderer, a, b, a, d);
        if(a != c) {
            SDL_RenderDrawLine(renderer, c, b, c, d);
        }

        ++x;
        y = sqrt(radius * radius - x * x);
    }
}

void outlinedCircle(SDL_Renderer* renderer, const vec2& center, const Color& outline, const Color& filling, const int& radius) {
    circleFill(renderer, center, radius, filling);
    circle(renderer, center, radius, outline);
}