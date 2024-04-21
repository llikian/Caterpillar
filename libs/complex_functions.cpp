#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

#include "complex_functions.h"

Complex makeComplex(const float& x, const float& y) {
    Complex z;

    z.x = x;
    z.y = y;

    return z;
}

Complex makeComplexExp(const float& r, const float& theta) {
    return makeComplex(r * cos(theta), r * sin(theta));
}

Complex operator +(const Complex& a, const Complex& b) {
    return makeComplex(a.x + b.x, a.y + b.y);
}

void operator +=(Complex& a, const Complex& b) {
    a = a + b;
}

Complex operator -(const Complex& a, const Complex& b) {
    return makeComplex(a.x - b.x, a.y - b.y);
}

Complex operator -(const Complex& z) {
    return makeComplex(-z.x, -z.y);
}

void operator -=(Complex& a, const Complex& b) {
    a = a - b;
}

Complex operator *(const float& lambda, const Complex& z) {
    return makeComplex(lambda * z.x, lambda * z.y);
}

Complex operator *(const Complex& z, const float& lambda) {
    return lambda * z;
}

void operator *=(Complex& z, const float& lambda) {
    z = lambda * z;
}

Complex operator *(const Complex& a, const Complex& b) {
    return makeComplex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

void operator *=(Complex& a, const Complex& b) {
    a = a * b;
}

Complex operator /(const Complex& z, const float& lambda) {
    return z * (1.f / lambda);
}

void operator /=(Complex& z, const float& lambda) {
    z = z / lambda;
}

Complex operator /(const float& lambda, const Complex& z) {
    return makeComplex((lambda * z.x) / (pow(z.x, 2) + pow(z.y, 2)), (-lambda * z.y) / (pow(z.x, 2) + pow(z.y, 2)));
}

Complex operator /(const Complex& a, const Complex& b) {
    return makeComplex((a.x * b.x + a.y * b.y) / (pow(b.x, 2) + pow(b.y, 2)), (-a.x * b.y + a.y * b.x) / (pow(b.x, 2) + pow(b.y, 2)));
}

void operator /=(Complex& a, const Complex& b) {
    a = a / b;
}

bool operator ==(const Complex& a, const Complex& b) {
    return (a.x == b.x) && (a.y == b.y);
}

bool operator !=(const Complex& a, const Complex& b) {
    return !(a == b);
}

Complex conjugue(const Complex& z) {
    return makeComplex(z.x, -z.y);
}

float rad(const float& deg) {
    return deg * PI / 180.f;
}

float deg(const float& rad) {
    return 180.f * rad / PI;
}

Complex scaleComplex(const Complex& z, const Complex& z0, const float& lambda) {
    return lambda * (z - z0) + z0;
}

Complex rotateComplex(const Complex& z, const Complex& z0, const float& theta_deg) {
    Complex t = makeComplexExp(1, rad(theta_deg));
    return t * (z - z0) + z0;
}

float module(const Complex& z) {
    return sqrt(z.x * z.x + z.y * z.y);
}

bool isInCircle(const Complex& z, const Complex& z0, const int& radius) {
    return module(z - z0) <= radius;
}

float arg(const Complex& z) {
    return atan2f(z.y, z.x);
}

float argDeg(const Complex& z) {
    return 180.f * arg(z) / PI;
}

Complex unitVector(const Complex& z) {
    return z / module(z);
}

float dotProduct(const Complex& a, const Complex& b) {
    return a.x * b.x + a.y * b.y;
}

float angle(const Complex& a, const Complex& b) {
    return acos(dotProduct(a, b) / (module(a) * module(b)));
}

float manhattanDistance(const Complex& z) {
    return fabs(z.x) + fabs(z.y);
}

bool isInDiamond(const Complex& z, const Complex& z0, const int& radius) {
    return manhattanDistance(z - z0) <= radius;
}

float perpDotProduct(const Complex& A, const Complex& B) {
    return dotProduct(makeComplex(-A.y, A.x), B);
}

float triangleArea(const Complex& A, const Complex& B, const Complex& C) {
    return fabs(0.5 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)));
}

void printComplex(const Complex& z) {
    std::cout << "( " << z.x << " ; " << z.y << " )" << std::endl;
}

int randint(const int& a, const int& b) {
    return std::rand() % (b - a + 1) + a;
}


float randfloat(const float& a, const float& b) {
    return a + std::rand() / (RAND_MAX / (b - a));
}

#pragma clang diagnostic pop