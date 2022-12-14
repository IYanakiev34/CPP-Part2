#ifndef DERIVED1_H
#define DERIVED1_H

#include "basic.h"
#include <iostream>

class Deriv1 : virtual public Basic
{
public:
    Deriv1()
    {
        std::cout << "Derived1 constructor called\n";
    }
};

#endif