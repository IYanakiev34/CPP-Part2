#ifndef DERIVED_H
#define DERIVED_H

#include "base.h"
#include <iostream>
class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived default constructor\n";
    }

    Derived(Derived const &other) : Base(std::move(const_cast<Derived &>(other)))
    {
        std::cout << "Derived copy called\n";
    }

    Derived(Derived &&tmp) : Base(tmp)
    {
        std::cout << "Derived move called\n";
    }
};
#endif