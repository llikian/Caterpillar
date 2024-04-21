#include "caterpillar.h"
#include "graphic_functions.h"

// STRUCTURES INITIALISATION
Particle makeParticle(const Complex& z, const Complex& v, const int& rmin, const int& rmax) {
    Particle p;

    p.z = z;
    p.v = v;
    p.F = ORIGIN;
    p.r = randint(rmin, rmax); // Random radius between rmin and rmax

    p.h = randfloat(0, 360);
    p.s = randfloat(100, 100);
    p.l = randfloat(50, 50);

    return p;
}

Caterpillar makeCaterpillar(const Complex& pos, const Complex& speed, const int& n, const int& rmin, const int& rmax) {
    Caterpillar c;

    c.n = n;

    for(int i = 0 ; i < n ; ++i) {
        c.p[i] = makeParticle(pos, speed, rmin, rmax);
    }

    return c;
}

World makeWorld(const int& np, const int& n, const int& rmin, const int& rmax, const int& anim) {
    World w;

    w.anim = anim;
    w.n = 1;

    Complex pos = M_O, speed = ORIGIN;

    for(int i = 0 ; i < w.n ; ++i) {
        if(anim == 2) {
            pos = makeComplex(3 * DX / 4.f, DY / 2.f);
        } else if(anim == 3) {
            speed = makeComplex(randfloat(-50, 50), randfloat(-50, 50));
            w.n = n;
        } else if(anim == 5) {
            w.n = n;
        }

        w.c[i] = makeCaterpillar(pos, speed, np, rmin, rmax);
    }

    return w;
}

//// STRUCTURES UPDATE
void updateParticle(World& w, const int& caterpillar, const int& particle) // World containing the particle, caterpillar index, particle index
{
    if(w.anim == 3) // Gravity and collisions
    {
        w.c[caterpillar].p[particle].F = makeComplex(0, 9.81);

        if(w.c[caterpillar].p[particle].z.x < float(w.c[caterpillar].p[particle].r) / 2 - 1) {
            w.c[caterpillar].p[particle].v = FRICTION * -conjugue(w.c[caterpillar].p[particle].v);
            w.c[caterpillar].p[particle].z += makeComplex(float(w.c[caterpillar].p[particle].r) / 2, 0);
        } else if(w.c[caterpillar].p[particle].z.x > DX - float(w.c[caterpillar].p[particle].r) / 2 + 1) {
            w.c[caterpillar].p[particle].v = FRICTION * -conjugue(w.c[caterpillar].p[particle].v);
            w.c[caterpillar].p[particle].z -= makeComplex(float(w.c[caterpillar].p[particle].r) / 2, 0);
        }

        if(w.c[caterpillar].p[particle].z.y < float(w.c[caterpillar].p[particle].r) / 2 - 1) {
            w.c[caterpillar].p[particle].v = FRICTION * conjugue(w.c[caterpillar].p[particle].v);
            w.c[caterpillar].p[particle].z += makeComplex(0, float(w.c[caterpillar].p[particle].r) / 2);
        } else if(w.c[caterpillar].p[particle].z.y > DY - float(w.c[caterpillar].p[particle].r) / 2 + 1) {
            w.c[caterpillar].p[particle].v = FRICTION * conjugue(w.c[caterpillar].p[particle].v);
            w.c[caterpillar].p[particle].z -= makeComplex(0, float(w.c[caterpillar].p[particle].r) / 2);
        }
    } else {
        w.c[caterpillar].p[particle].F = ORIGIN;
    }

    w.c[caterpillar].p[particle].v += (w.c[caterpillar].p[particle].F / MASS) * DT;
    w.c[caterpillar].p[particle].z += w.c[caterpillar].p[particle].v * DT;
}

void animations(World& w) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    Complex mouse = makeComplex((float) x, (float) y);

    for(int i = 0 ; i < w.n ; ++i) {
        switch(w.anim) {
            case 0: // First particle follows mouse
                w.c[i].p[0].v = mouse - w.c[i].p[0].z;
                break;
            case 1: // First particle is on mouse
                w.c[i].p[0].z = mouse;
                break;
            case 2: // First particle draws a circle
                w.c[i].p[0].z = M_O + makeComplexExp(250, (float) SDL_GetTicks() * 0.004f);
                break;
            case 3: // Caterpillars fall and collide
                break;
            case 4: // First particle is the reflexion point of the mouse
                w.c[i].p[0].z = 2 * M_O - mouse;
                break;
            case 5: // Snowflake
                w.c[i].p[0].z = rotateComplex(mouse, M_O, 360.f * (float) i / (float) w.n);
            default:
                break;
        }
    }
}

void updateCaterpillar(World& w, const int& caterpillar) {
    animations(w);

    updateParticle(w, caterpillar, 0);

    for(int i = 1 ; i < w.c[caterpillar].n ; ++i) {
        w.c[caterpillar].p[i].v = w.c[caterpillar].p[i - 1].z - w.c[caterpillar].p[i].z;

        updateParticle(w, caterpillar, i);
    }
}

void updateWorld(World& w) {
    for(int i = 0 ; i < w.n ; ++i) {
        updateCaterpillar(w, i);
    }
}

//// STRUCTURES DRAW
void drawParticle(const Particle& p, const Color& color, SDL_Renderer* renderer) {
//    setColor(renderer, WHITE);
//    SDL_RenderDrawPoint(renderer, p.z.x, p.z.y);
    Color filling = makeColor(color.r, color.g, color.b, 255 / 5);
    outlinedCircle(renderer, p.z, color, filling, p.r);
}

void drawCaterpillar(const Caterpillar& c, SDL_Renderer* renderer) {
    Color color;

    for(int i = c.n - 1 ; i >= 0 ; --i) {
        color = hsl((float) i * 360 / (float) c.n, 100, 50);
//        color = hsl(0, 0, (float)i * 100 / (float)c.n);
//        color = hsl(c.p[i].h, c.p[i].s, c.p[i].l);
        drawParticle(c.p[i], color, renderer);
    }
}

void drawWorld(const World& w, SDL_Renderer* renderer) {
    for(int i = 0 ; i < w.n ; ++i) {
        drawCaterpillar(w.c[i], renderer);
    }
}

//// OTHER FUNCTIONS & PROCEDURES
void switchAnimation(World& w, const int& np, const int& n, const int& rmin, const int& rmax, const Uint8* keyboard, Uint32& repeat_Z, Uint32& repeat_S) {
    if(keyboard[SDL_SCANCODE_W] && SDL_GetTicks() - repeat_Z > KEYREPEAT) // Next animation
    {
        if(w.anim < ANIMS) {
            ++w.anim;
            w = makeWorld(np, n, rmin, rmax, w.anim);
            repeat_Z = SDL_GetTicks();
        }
    } else if(keyboard[SDL_SCANCODE_S] && SDL_GetTicks() - repeat_S > KEYREPEAT) // Previous animation
    {
        if(w.anim > 0) {
            --w.anim;
            w = makeWorld(np, n, rmin, rmax, w.anim);
            repeat_S = SDL_GetTicks();
        }
    }
}

void changeCaterpillarNum(World& w, const int& np, int& n, const int& rmin, const int& rmax, const Uint8* keyboard, Uint32& repeat_I, Uint32& repeat_K) {
    if(keyboard[SDL_SCANCODE_I] && n < MAXC && SDL_GetTicks() - repeat_I > KEYREPEAT) {
        ++n;
        w = makeWorld(np, n, rmin, rmax, w.anim);
        repeat_I = SDL_GetTicks();
    } else if(keyboard[SDL_SCANCODE_K] && n > 1 && SDL_GetTicks() - repeat_K > KEYREPEAT) {
        --n;
        w = makeWorld(np, n, rmin, rmax, w.anim);
        repeat_K = SDL_GetTicks();
    }
}

void toggleWinClear(bool& enableClear, SDL_Renderer* renderer, const Uint8* keyboard, Uint32& repeat_RETURN, Uint32& repeat_SPACE) {
    if(keyboard[SDL_SCANCODE_RETURN] && SDL_GetTicks() - repeat_RETURN > KEYREPEAT) {
        enableClear = !enableClear;
        repeat_RETURN = SDL_GetTicks();
    }
    if(enableClear) {
        SDL_RenderClear(renderer);
    } else if(keyboard[SDL_SCANCODE_SPACE] && SDL_GetTicks() - repeat_SPACE > KEYREPEAT) {
        SDL_RenderClear(renderer);
        repeat_SPACE = SDL_GetTicks();
    }
}

void toggleDraw(bool& enableDraw, const Uint8* keyboard, Uint32& repeat_D) {
    if(keyboard[SDL_SCANCODE_D] && SDL_GetTicks() - repeat_D > KEYREPEAT) {
        enableDraw = !enableDraw;
        repeat_D = SDL_GetTicks();
    }
}