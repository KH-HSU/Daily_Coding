#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
class Complex
{
    private:
        float real;
        float imaginary;
    public:
        void print();
        Complex(float = 0.0, float = 0.0); // constructor
        Complex operator+(Complex);
};
#endif