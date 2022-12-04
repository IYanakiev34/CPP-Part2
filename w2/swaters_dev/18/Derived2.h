//
// Created by Alex Swaters on 12/4/2022.
//

#ifndef INC_18_DERIVED2_H
#define INC_18_DERIVED2_H

#include <iostream>
#include "Base.h"

// Same as derived but call respective base ctor
class Derived2 : public Base
{
public:
    Derived2();
    Derived2(const Derived2 &other);
    Derived2(Derived2 &&other) noexcept;
};

Derived2::Derived2() : Base()
{
    std::cout << "Derived2 constructor call\n";
}

Derived2::Derived2(const Derived2 &other) : Base(other)
{
    std::cout << "Derived2 copy constructor call\n";
}

Derived2::Derived2(Derived2 &&other) noexcept : Base(std::move(other))
{
    std::cout << "Derived2 move constructor call\n";
}

#endif //INC_18_DERIVED2_H
