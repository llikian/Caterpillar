/******************************************************************************************************
 * @file  Application.hpp
 * @brief Declaration of the Application class
 ******************************************************************************************************/

#pragma once

extern "C" {
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
}

#include <unordered_map>

#include "core/Colony.hpp"
#include "utilities/draw.hpp"

#define WINDOW_FLAGS (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE)

/**
 * @class Application
 * @brief
 */
class Application {
public:
    Application();
    ~Application();

    void run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Event event;

    int width, height;

    bool stop, fullscreen;
    std::unordered_map<SDL_Scancode, bool> keysFlags;

    Point mouse;
    float timer;
    float dt;

    unsigned char behavior;

    Colony colony;

    void drawColony();
    void drawParticle(const Particle& particle);

    Texture* createTextureFromSurface(Surface* surface, bool freeSurface = true);

    void drawText(int x, int y, const Color& color, const std::string& text);
    void drawText(int x, int y, const Color& textColor, const Color& background, const std::string& text);
    void drawCenteredText(const Rect& reference, const Color& color, const std::string& text);

    void handleEvents();
    void handleInputs();
    void changeBehaviorTo();
};