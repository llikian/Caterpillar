#ifndef COMPLEX_FUNCTIONS
#define COMPLEX_FUNCTIONS

#include <iostream>
#include <cmath>
#include <cstdlib>

#define PI 3.141592653589793238462643383279502884L

typedef struct {
    float x, y;
} Complex;

//typedef Complex Vec2;

Complex makeComplex(const float& x, const float& y);
Complex makeComplexExp(const float& r, const float& theta);

Complex operator +(const Complex& a, const Complex& b);
void operator +=(Complex& a, const Complex& b);

Complex operator -(const Complex& a, const Complex& b);
Complex operator -(const Complex& z);
void operator -=(Complex& a, const Complex& b);

Complex operator *(const float& lambda, const Complex& z);
Complex operator *(const Complex& z, const float& lambda);
void operator *=(Complex& z, const float& lambda);

Complex operator *(const Complex& a, const Complex& b);
void operator *=(Complex& a, const Complex& b);

Complex operator /(const Complex& z, const float& lambda);
void operator /=(Complex& z, const float& lambda);

Complex operator /(const float& lambda, const Complex& z);
Complex operator /(const Complex& a, const Complex& b);
void operator /=(Complex& a, const Complex& b);

bool operator ==(const Complex& a, const Complex& b);
bool operator !=(const Complex& a, const Complex& b);

Complex conjugue(const Complex& z);

float rad(const float& deg);
float deg(const float& rad);

Complex scaleComplex(const Complex& z, const Complex& z0, const float& lambda);
Complex rotateComplex(const Complex& z, const Complex& z0, const float& theta_deg);

float module(const Complex& z);

bool isInCircle(const Complex& z, const Complex& z0, const int& radius);

float arg(const Complex& z);

float argDeg(const Complex& z);

Complex unitVector(const Complex& z);

float dotProduct(const Complex& a, const Complex& b);

float angle(const Complex& a, const Complex& b);

float manhattanDistance(const Complex& z);

bool isInDiamond(const Complex& z, const Complex& z0, const int& radius);

/* If = 0, vectors A & B are parallel
 * If > 0, B is counter clockwise to A
 * If < 0, B is clockwise to A
 */
float perpDotProduct(const Complex& A, const Complex& B);

float triangleArea(const Complex& A, const Complex& B, const Complex& C);

void printComplex(const Complex& z);

int randint(const int& a, const int& b);
float randfloat(const float& a, const float& b);


#endif