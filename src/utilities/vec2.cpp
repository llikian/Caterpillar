/******************************************************************************************************
 * @file  vec2.cpp
 * @brief Implementation of the vec2 class
 ******************************************************************************************************/

#include "vec2.hpp"

#include <random>

vec2::vec2() : SDL_FPoint(0, 0) { }

vec2::vec2(float x, float y) : SDL_FPoint(x, y) { }

vec2::vec2(float value) : SDL_FPoint(value, value) { }

float vec2::length() {
    return std::sqrt(x * x + y * y);
}

vec2 vec2::random(float min, float max) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_real_distribution<float> distribution(min, max);

    return vec2(distribution(generator), distribution(generator));
}

vec2 vec2::random(float minX, float maxX, float minY, float maxY) {
    std::random_device device;
    std::mt19937 generator(device());

    std::uniform_real_distribution<float> distributionX(minX, maxX);
    std::uniform_real_distribution<float> distributionY(minY, maxY);

    return vec2(distributionX(generator), distributionY(generator));
}

vec2& vec2::operator +=(const vec2& vec) {
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

vec2 operator +(const vec2& a, const vec2& b) {
    return vec2(a.x + b.x, a.y + b.y);
}

vec2 operator -(const vec2& a, const vec2& b) {
    return vec2(a.x - b.x, a.y - b.y);
}

vec2 operator *(float factor, const vec2& vec) {
    return vec2(factor * vec.x, factor * vec.y);
}

vec2 operator *(const vec2& vec, float factor) {
    return vec2(vec.x * factor, vec.y * factor);
}

vec2 operator *(const vec2& a, const vec2& b) {
    return vec2(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
