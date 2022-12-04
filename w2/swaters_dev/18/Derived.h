//
// Created by Alex Swaters on 12/4/2022.
//

#ifndef INC_18_DERIVED_H
#define INC_18_DERIVED_H

#include <iostream>
#include "Base.h"

class Derived : public Base
{
public:
    Derived();

    Derived(const Derived &other);

    Derived(Derived &&other) noexcept;
};

Derived::Derived()
{
    std::cout << "Derived constructor call\n";
}

Derived::Derived(const Derived &other)
{
    std::cout << "Derived copy constructor call\n";
}

Derived::Derived(Derived &&other) noexcept
{
    std::cout << "Derived move constructor call\n";
}

#endif //INC_18_DERIVED_H
