#ifndef MULTI_H
#define MULTI_H

#include "derived1.h"
#include "derived2.h"

class Multi : public Deriv1, public Deriv2
{
public:
    Multi() : Basic(10)
    {
        std::cout << static_cast<Basic *>(this) << "\n";
        std::cout << "Multi constructor called\n";
    };
};

#endif