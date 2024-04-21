/******************************************************************************************************
 * @file  Colony.cpp
 * @brief Implementation of the Colony class
 ******************************************************************************************************/

#include "Colony.hpp"
#include "utilities/utility.hpp"

std::vector<Particle>& Colony::operator [](unsigned int index) { return caterpillars[index]; }

void Colony::addCaterpillar(unsigned int particles, const vec2& position) {
    caterpillars.emplace_back();
    Caterpillar& caterpillar = caterpillars[caterpillars.size() - 1];

    for(int i = 0 ; i < particles ; ++i) {
        caterpillar.emplace_back(position,
                                 vec2(),
                                 vec2(),
                                 randomFloat(7, 12),
                                 i * (360 / particles));
    }
}

void Colony::removeCaterpillar() {
    if(caterpillars.size() > 1) {
        caterpillars.pop_back();
    }
}
