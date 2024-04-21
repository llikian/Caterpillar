#include "graphic_functions.h"

void setColor(SDL_Renderer* renderer, const Color& color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

SDL_Rect makeRect(const int& x, const int& y, const int& w, const int& h) {
    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    return rect;
}

void circle(SDL_Renderer* renderer, const Complex& center, const int& radius, const Color& color) {
    int x = 0, y = radius;

    setColor(renderer, color);

    while(x <= y) {
        SDL_Point points[8] = {{x,  y},
                               {-x, y},
                               {x,  -y},
                               {-x, -y},
                               {y,  x},
                               {-y, x},
                               {y,  -x},
                               {-y, -x}};

        for(SDL_Point& point: points) {
            point.x += (int) center.x;
            point.y += (int) center.y;
        }

        SDL_RenderDrawPoints(renderer, points, 8);

        ++x;
        y = (int) sqrt(radius * radius - x * x);
    }
}

void circleFill(SDL_Renderer* renderer, const Complex& center, const int& radius, const Color& color) {
    int x = 0, y = radius, a, b, c, d;

    setColor(renderer, color);

    while(x <= radius) {
        a = (int) center.x + x;
        b = (int) center.y + y;
        c = (int) center.x - x;
        d = (int) center.y - y;

        SDL_RenderDrawLine(renderer, a, b, a, d);
        SDL_RenderDrawLine(renderer, c, b, c, d);

        ++x;
        y = (int) sqrt(radius * radius - x * x);
    }
}

void outlinedCircle(SDL_Renderer* renderer, const Complex& center, const Color& outline, const Color& filling, const int& radius) {
    circleFill(renderer, center, radius, filling);
    circle(renderer, center, radius, outline);
}