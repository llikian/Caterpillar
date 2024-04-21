#ifndef COLOR_FUNCTIONS
#define COLOR_FUNCTIONS

#include <cmath>

#define BLACK makeColor(0, 0, 0)
#define DARK_GREY makeColor(20, 20, 20)
#define GREY makeColor(125, 125, 125)
#define WHITE makeColor(255, 255, 255)
#define RED makeColor(255, 0, 0)
#define YELLOW makeColor(255, 255, 0)
#define GREEN makeColor(0, 255, 0)
#define CYAN makeColor(0, 255, 255)
#define BLUE makeColor(0, 0, 255)
#define PURPLE makeColor(255, 0, 255)

typedef struct {
    unsigned char r, g, b, a;
} Color;

Color makeColor(const unsigned char& r, const unsigned char& g, const unsigned char& b);
Color makeColor(const unsigned char& r, const unsigned char& g, const unsigned char& b, const unsigned char& a);

Color operator *(const Color& c, const float& lambda);
Color operator *(const float& lambda, const Color& c);
void operator *=(Color& c, const float& lambda);

Color operator /(const Color& c, const float& lambda);
void operator /=(Color& c, const float& lambda);

Color operator +(const Color& a, const Color& b);
void operator +=(Color& a, const Color& b);

Color operator -(const Color& a, const Color& b);
void operator -=(Color& a, const Color& b);

Color colorInterpolation(const Color& a, const Color& b, const float& t);

Color hsl(const float& h, float s, float l);

#endif