#include "complex.h"

int main()
{
    Complex x(1.0, 2.0), y(2, 3), z(0, 0);
    z = x + y;    // can imagine that overloading is like x.+(y)
    z.print();
}

// g++ main.cpp complex.cpp