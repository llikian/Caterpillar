/******************************************************************************************************
 * @file  vec2.hpp
 * @brief Declaration of the vec2 struct
 ******************************************************************************************************/

#pragma once

extern "C" {
#include <SDL2/SDL.h>
}

/**
 * @struct vec2
 * @brief Functions as a child of the C like struct SDL_FPoint,
 *        in order to add C++ like functionality such as constructors
 *        and methods.
 */
struct vec2 : SDL_FPoint {
    /**
     * @brief Default constructor
     */
     vec2();

    /**
     * @brief Constructs a point at coordinates (x ; y)
     * @param x The x coordinate of the point
     * @param y The y coordinate of the point
     */
    vec2(float x, float y);

    /**
     * @brief Constructs a point at coordinates (value ; value)
     * @param value The value of the coordinates of the point
     */
    vec2(float value);

    /**
     * @brief Calculates the length of the vector
     * @return The length of the vector
     */
    float length();

    /**
     * @brief Generates a random point with both parts in the same range
     *
     * @param min The minimum value for x and y
     * @param max The maximum value for x and y
     *
     * @return A random point
     */
    static vec2 random(float min, float max);

    /**
     * @brief Generates a random point
     *
     * @param minX The minimum value for x
     * @param maxX The maximum value for x
     * @param minY The minimum value for y
     * @param maxY The maximum value for y
     *
     * @return A random point
     */
    static vec2 random(float minX, float maxX, float minY, float maxY);


    /**
     * @brief Adds the coordinates of the right operand to the left operand
     * @param vec The coordinates that will be added
     * @return A reference to the left operand
     */
    vec2& operator +=(const vec2& vec);
};

/**
 * @brief Adds a point's coordinates to another
 * @param a The first point
 * @param b The second point
 * @return The sum a + b
 */
vec2 operator+(const vec2& a, const vec2& b);

/**
 * @brief Substracts a point's coordinates to another
 * @param a The first point
 * @param b The second point
 * @return The substraction b - a
 */
vec2 operator-(const vec2& a, const vec2& b);

/**
 * @brief Multiplies a point by a factor
 * @param factor The factor
 * @param vec The point
 * @return The product factor * vec
 */
vec2 operator* (float factor, const vec2& vec);

/**
 * @brief Multiplies a point by a factor
 * @param factor The factor
 * @param vec The point
 * @return The product vec * factor
 */
vec2 operator* (const vec2& vec, float factor);

/**
 * @brief Multiplies two points with each other using the complex formula
 * @param a The first point
 * @param b The second point
 * @return The product of a * b
 */
vec2 operator* (const vec2& a, const vec2& b);