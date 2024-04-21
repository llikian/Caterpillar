/******************************************************************************************************
 * @file  Application.cpp
 * @brief Implementation of the Application class
 ******************************************************************************************************/

#include "Application.hpp"

#include <stdexcept>
#include <string>

#include "utilities/HSL.hpp"

Application::Application()
    : window(), renderer(), font(), event(),
      width(1280), height(780),
      stop(), fullscreen(),
      timer(), dt(),
      behavior() {

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error(std::string("SDL_Init failed : ").append(SDL_GetError()));
    }

    if(TTF_Init() != 0) {
        throw std::runtime_error(std::string("TTF_Init failed : ") + SDL_GetError());
    }

    window = SDL_CreateWindow("Pancake Media Player",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height, WINDOW_FLAGS);

    if(!window) {
        throw std::runtime_error(std::string("Window was not created : ").append(SDL_GetError()));
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer) {
        throw std::runtime_error(std::string("Renderer was not created : ").append(SDL_GetError()));
    }

    font = TTF_OpenFont("data/fonts/courbd.ttf", 20);
    if(!font) {
        throw std::runtime_error(std::string("Font was not opened : ") + SDL_GetError());
    }

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_WarpMouseInWindow(window, width / 2, height / 2);

    colony.addCaterpillar(10, vec2(width / 2.0f, height / 2.0f));
}

Application::~Application() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::run() {
    const Color white(255);
    timer = static_cast<float>(SDL_GetTicks64()) / 1000.0f;

    while(!stop) {
        handleEvents();

        SDL_GetMouseState(&mouse.x, &mouse.y);

        dt = 10.0f * (static_cast<float>(SDL_GetTicks64()) / 1000.0f - timer);
        timer = static_cast<float>(SDL_GetTicks64()) / 1000.0f;

        drawText(10, 10, white, "Caterpillars : " + std::to_string(colony.caterpillars.size()));
        drawText(10, 30, white, "Behavior num : " + std::to_string(behavior));

        drawColony();

        SDL_RenderPresent(renderer);
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_RenderClear(renderer);
    }
}

void Application::drawColony() {
    const vec2 center(width / 2.0f, height / 2.0f);
    const vec2 mouseF(mouse.x, mouse.y);

    switch(behavior) {
        case 0: // First particle follows mouth
            colony[0][0].speed = mouseF - colony[0][0].pos;
            colony[0][0].pos += colony[0][0].speed * dt;

            drawParticle(colony[0][0]);

            for(int i = 1 ; i < colony[0].size() ; ++i) {
                colony[0][i].speed = colony[0][i - 1].pos - colony[0][i].pos;
                colony[0][i].pos += colony[0][i].speed * dt;

                drawParticle(colony[0][i]);
            }

            break;
        case 1: // First particle is on mouth
            colony[0][0].pos = mouseF;

            drawParticle(colony[0][0]);

            for(int i = 1 ; i < colony[0].size() ; ++i) {
                colony[0][i].speed = colony[0][i - 1].pos - colony[0][i].pos;
                colony[0][i].pos += colony[0][i].speed * dt;

                drawParticle(colony[0][i]);
            }

            break;
        case 2: // First particle draws a circle
            colony[0][0].pos = center + vec2(cosf(timer), sinf(timer)) * (std::min(width, height) / 2.5f);
            drawParticle(colony[0][0]);

            for(int i = 1 ; i < colony[0].size() ; ++i) {
                colony[0][i].speed = colony[0][i - 1].pos - colony[0][i].pos;
                colony[0][i].pos += colony[0][i].speed * dt;

                drawParticle(colony[0][i]);
            }

            break;
        case 3: // Caterpillars experience gravity and collisions with walls
            for(Caterpillar& caterpillar: colony.caterpillars) {
                caterpillar[0].force.x = 0;
                caterpillar[0].force.y = 9.81;
                caterpillar[0].speed += caterpillar[0].force * dt;
                caterpillar[0].pos += caterpillar[0].speed * dt;

                drawParticle(caterpillar[0]);

                if(caterpillar[0].pos.x <= caterpillar[0].radius || caterpillar[0].pos.x >= width - caterpillar[0].radius) {
                    caterpillar[0].speed.x *= -1;
                }

                if(caterpillar[0].pos.y <= caterpillar[0].radius || caterpillar[0].pos.y >= height - caterpillar[0].radius) {
                    caterpillar[0].speed.y *= -1;
                }

                for(int i = 1 ; i < caterpillar.size() ; ++i) {
                    caterpillar[i].speed = caterpillar[i - 1].pos - caterpillar[i].pos;
                    caterpillar[i].pos += caterpillar[i].speed * dt;

                    drawParticle(caterpillar[i]);
                }
            }

            break;
        case 4: // First particle is the reflexion point of the mouse
            colony[0][0].pos = (center - mouseF) + center;

            drawParticle(colony[0][0]);

            for(int i = 1 ; i < colony[0].size() ; ++i) {
                colony[0][i].speed = colony[0][i - 1].pos - colony[0][i].pos;
                colony[0][i].pos += colony[0][i].speed * dt;

                drawParticle(colony[0][i]);
            }

            break;
        case 5: // Snowflake
            for(int i = 0 ; i < colony.caterpillars.size() ; ++i) {
                float angle = static_cast<float>(i) / static_cast<float>(colony.caterpillars.size());
                colony[i][0].pos = vec2(cosf(2.0f * M_PIf * angle), sinf(2.0f * M_PIf * angle)) * (mouseF - center) + center;

                drawParticle(colony[i][0]);

                for(int j = 1 ; j < colony[i].size() ; ++j) {
                    colony[i][j].speed = colony[i][j - 1].pos - colony[i][j].pos;
                    colony[i][j].pos += colony[i][j].speed * dt;

                    drawParticle(colony[i][j]);
                }
            }

        default:
            break;
    }
}

void Application::drawParticle(const Particle& particle) {
    const Color outside = HSL::hueToRGBA(particle.hue);
    const Color inside(outside.r, outside.g, outside.b, 255 / 5);

    outlinedCircle(renderer, particle.pos, outside, inside, static_cast<int>(particle.radius));
}

Texture* Application::createTextureFromSurface(Surface* surface, bool freeSurface) {
    if(!surface) {
        throw std::runtime_error(std::string("Surface wasn't defined (nullptr) : ") + SDL_GetError());
    }

    Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    if(freeSurface) {
        SDL_FreeSurface(surface);
    }

    if(!texture) {
        SDL_FreeSurface(surface);
        throw std::runtime_error(std::string("Couldn't create texture from surface : ") + SDL_GetError());
    }

    return texture;
}

void Application::drawText(int x, int y, const Color& color, const std::string& text) {
    Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if(!surface) {
        throw std::runtime_error{std::string("TTF_RenderText_Solid failed : ") + SDL_GetError()};
    }

    Texture* texture = createTextureFromSurface(surface, false);

    SDL_Rect rect(x, y, surface->w, surface->h);
    SDL_RenderCopy(renderer, texture, nullptr, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Application::drawText(int x, int y, const Color& textColor, const Color& background, const std::string& text) {
    Surface* surface = TTF_RenderText(font, text.c_str(), textColor, background);
    if(!surface) {
        throw std::runtime_error{std::string("TTF_RenderText failed : ") + SDL_GetError()};
    }

    Texture* texture = createTextureFromSurface(surface, false);

    SDL_Rect rect(x, y, surface->w, surface->h);
    SDL_RenderCopy(renderer, texture, nullptr, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Application::drawCenteredText(const Rect& reference, const Color& color, const std::string& text) {
    Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if(!surface) {
        throw std::runtime_error{std::string("TTF_RenderText failed : ") + SDL_GetError()};
    }

    Texture* texture = createTextureFromSurface(surface, false);

    SDL_Rect rect(reference.x + (reference.w - surface->w) / 2, reference.y + (reference.h - surface->h) / 2, surface->w, surface->h);
    SDL_RenderCopy(renderer, texture, nullptr, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Application::handleEvents() {
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_KEYDOWN:
                handleInputs();

                break;
            case SDL_KEYUP:
                if(keysFlags.contains(event.key.keysym.scancode)) {
                    keysFlags[event.key.keysym.scancode] = false;
                }

                break;
            case SDL_QUIT:
                stop = true;

                break;
            case SDL_WINDOWEVENT:
                if(event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    SDL_GetWindowSize(window, &width, &height);
                }

                break;
            default:
                break;
        }
    }
}

void Application::handleInputs() {
    const SDL_Scancode scancode = event.key.keysym.scancode;

    switch(scancode) {
        case SDL_SCANCODE_ESCAPE:
            stop = true;

            break;
        case SDL_SCANCODE_F11:
            if(!keysFlags[scancode]) {
                SDL_SetWindowFullscreen(window, fullscreen ? 0 : SDL_WINDOW_FULLSCREEN);
                fullscreen = !fullscreen;
                keysFlags[SDL_SCANCODE_F11] = true;
            }

            break;
        case SDL_SCANCODE_UP:
            if(!keysFlags[scancode]) {
                if(behavior < 5) {
                    ++behavior;
                    changeBehaviorTo();
                }
            }

            break;
        case SDL_SCANCODE_DOWN:
            if(!keysFlags[scancode]) {
                if(behavior > 0) {
                    --behavior;
                    changeBehaviorTo();
                }
            }

            break;
        case SDL_SCANCODE_T:
            if(!keysFlags[scancode]) {
                colony.addCaterpillar(10, vec2(width / 2.0f, height / 2.0f));

                if(behavior == 3) {
                    colony[colony.caterpillars.size() - 1][0].pos = vec2::random(10.0f, width - 10.0f, 10.0f, height - 10.0f);
                    colony[colony.caterpillars.size() - 1][0].speed = vec2::random(-100.0f, 100.0f);
                }
            }

            break;
        case SDL_SCANCODE_G:
            if(!keysFlags[scancode]) {
                colony.removeCaterpillar();

                if(behavior == 3) {
                    colony[colony.caterpillars.size() - 1][0].pos.x = width / 2.0f;
                    colony[colony.caterpillars.size() - 1][0].pos.y = height / 2.0f;
                    colony[colony.caterpillars.size() - 1][0].speed = vec2::random(-50.0f, 50.0f);
                }
            }

            break;
        default:
            break;
    }
}

void Application::changeBehaviorTo() {
    switch(behavior) {
        case 3:
            for(Caterpillar& caterpillar: colony.caterpillars) {
                caterpillar[0].speed = vec2::random(-50.0f, 50.0f);
                for(Particle& particle : caterpillar) {
                    particle.pos.x = width / 2.0f;
                    particle.pos.y = height / 2.0f;
                }
            }

            break;

        default:
            break;
    }
}
