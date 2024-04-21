/******************************************************************************************************
 * @file  Particle.hpp
 * @brief Declaration of the Particle class
 ******************************************************************************************************/

#pragma once

#include "utilities/Color.hpp"
#include "utilities/vec2.hpp"

/**
 * @struct Particle
 * @brief
 */
struct Particle {
    Particle(const vec2& pos, const vec2& speed, const vec2& force, float radius, unsigned short hue);

    vec2 pos;
    vec2 speed;
    vec2 force;

    float radius;
    unsigned short hue;
};