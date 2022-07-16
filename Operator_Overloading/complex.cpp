#include "complex.h"

Complex::Complex(float x, float y)
{
    real = x;
    imaginary = y;
}

void Complex::print()
{
    cout << '(' << real << "," << imaginary << ')' << "\n";
}

Complex Complex::operator+(Complex y)
{
    float r = y.real;
    float i = y.imaginary;
    Complex z(real + r, imaginary + i);
    return z;
}