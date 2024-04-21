#ifndef CATERPILLAR
#define CATERPILLAR

#include "color_functions.h"
#include "complex_functions.h"
#include "graphic_functions.h"
#include <SDL2/SDL.h>

#define DX 1300 // Window width
#define DY 800 // Window heigth
#define M_O makeComplex(DX / 2.f, DY / 2.f) // Window center
#define ORIGIN makeComplex(0, 0)

#define MAXP 100 // Max number of particles in a caterpillar
#define MASS 10 // Mass of particles
#define MAXC 100 // Max number of colony
#define ANIMS 5 // Current number of animations

#define FRICTION 1.f // Coefficient of speed loss when there is a collision

#define DT 0.015f
#define KEYREPEAT 200 // Number of ms before a key is repeated

typedef struct {
    Complex z; // Position
    Complex v; // Speed
    Complex F; // Force
    int r; // Radius
    float h; // Hue
    float s; // Saturation
    float l; // Light
} Particle;

typedef struct {
    Particle p[MAXP];
    int n;
} Caterpillar;

typedef struct {
    Caterpillar c[MAXC];
    int n, anim; // If different colony have different animations, -1
} World;

// STRUCTURES INITIALISATION
Particle makeParticle(const Complex& z, const Complex& v, const int& rmin, const int& rmax);
Caterpillar makeCaterpillar(const Complex& pos, const Complex& speed, const int& n, const int& rmin, const int& rmax);
World makeWorld(const int& np, const int& n, const int& rmin, const int& rmax, const int& anim);

//// STRUCTURES UPDATE
void animations(World& w);

void updateParticle(World& w, const int& caterpillar, const int& particle);
void updateCaterpillar(World& w, const int& caterpillar);
void updateWorld(World& w);

//// STRUCTURES DRAW
void drawParticle(const Particle& p, const Color& color, SDL_Renderer* renderer);
void drawCaterpillar(const Caterpillar& c, SDL_Renderer* renderer);
void drawWorld(const World& w, SDL_Renderer* renderer);

//// OTHER FUNCTIONS & PROCEDURES
void switchAnimation(World& w, const int& np, const int& n, const int& rmin, const int& rmax, const Uint8* keyboard, Uint32& repeat_Z, Uint32& repeat_S);
void changeCaterpillarNum(World& w, const int& np, int& n, const int& rmin, const int& rmax, const Uint8* keyboard, Uint32& repeat_I, Uint32& repeat_K);

void toggleWinClear(bool& enableClear, SDL_Renderer* renderer, const Uint8* keyboard, Uint32& repeat_RETURN, Uint32& repeat_SPACE);
void toggleDraw(bool& enableDraw, const Uint8* keyboard, Uint32& repeat_D);
#endif