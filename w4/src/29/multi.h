#ifndef MULTI_H
#define MULTI_H

#include "derived1.h"
#include "derived2.h"

class Multi : public Deriv1, public Deriv2
{
public:
    Multi();
};

#endif