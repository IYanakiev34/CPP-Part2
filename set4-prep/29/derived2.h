#ifndef DERIVED2_H
#define DERIVED2_H

#include "basic.h"
#include <iostream>

class Deriv2 : virtual public Basic
{
public:
    Deriv2()
    {
        std::cout << "Derived 2 constructor callled\n";
    }
};

#endif