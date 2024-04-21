#include <SDL2/SDL.h>
#include <iostream>
#include "color_functions.h"
#include "caterpillar.h"
#include "graphic_functions.h"

int main(int /* argc */, char** /* argv */) {
    srand(time(nullptr));

    // Initializes SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Initializes the window and the renderer
    SDL_Window* window = SDL_CreateWindow("Learning SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DX, DY, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // Allows transparency

    // Initializes other variables
    SDL_Event event;
    const Uint8* keyboard;

    bool stop = false, enableClear = true, enableDraw = true;
    int np = 10, n = 5, rmin = 5, rmax = 10;

    World w = makeWorld(np, n, rmin, rmax, 0);

    // Key repeats timer checks
    Uint32 repeat_Z = -KEYREPEAT;
    Uint32 repeat_S = -KEYREPEAT;
    Uint32 repeat_I = -KEYREPEAT;
    Uint32 repeat_K = -KEYREPEAT;
    Uint32 repeat_RETURN = -KEYREPEAT;
    Uint32 repeat_SPACE = -KEYREPEAT;
    Uint32 repeat_D = -KEYREPEAT;

    // Main loop
    while(!stop) {
        keyboard = SDL_GetKeyboardState(nullptr);

        // Sets the background color
        setColor(renderer, DARK_GREY);

        toggleWinClear(enableClear, renderer, keyboard, repeat_RETURN, repeat_SPACE);
        toggleDraw(enableDraw, keyboard, repeat_D);

        switchAnimation(w, np, n, rmin, rmax, keyboard, repeat_Z, repeat_S);
        changeCaterpillarNum(w, np, n, rmin, rmax, keyboard, repeat_I, repeat_K);

        if(enableDraw) {
            drawWorld(w, renderer);
        }
        updateWorld(w);

        // Updates the changes
        SDL_RenderPresent(renderer);

        // Handles closing the window
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT || keyboard[SDL_SCANCODE_ESCAPE]) {
                stop = true;
            }
        }
    }

    // Clean up SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}