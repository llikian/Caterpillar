/******************************************************************************************************
 * @file  Colony.hpp
 * @brief Declaration of the Colony class
 ******************************************************************************************************/

#pragma once

#include <vector>

#include "core/Particle.hpp"
#include "utilities/vec2.hpp"

typedef std::vector<Particle> Caterpillar;

/**
 * @class Colony
 * @brief
 */
class Colony {
public:
    std::vector<Caterpillar> caterpillars;

    Caterpillar& operator[](unsigned int index);
    void addCaterpillar(unsigned int particles, const vec2& position);
    void removeCaterpillar();
};