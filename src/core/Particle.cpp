/******************************************************************************************************
 * @file  Particle.cpp
 * @brief Implementation of the Particle class
 ******************************************************************************************************/

#include "Particle.hpp"

Particle::Particle(const vec2& pos, const vec2& speed, const vec2& force, float radius, unsigned short hue)
    : pos(pos), speed(speed), force(force), radius(radius), hue(hue) { }

