/******************************************************************************************************
 * @file  utiliy.cpp
 * @brief 
 ******************************************************************************************************/

#include "utility.hpp"

float randomFloat(float min, float max) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_real_distribution<float> distribution(min, max);

    return distribution(generator);
}
