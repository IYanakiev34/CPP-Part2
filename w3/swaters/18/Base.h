//
// Created by Alex Swaters on 12/4/2022.
//

#ifndef INC_18_BASE_H
#define INC_18_BASE_H

#include <iostream>

class Base
{
public:
    Base();

    Base(const Base &other);

    Base(Base &&other) noexcept;
};

inline Base::Base()
{
    std::cout << "Base constructor call\n";
}

inline Base::Base(const Base &other)
{
    std::cout << "Base copy constructor call\n";
}

inline Base::Base(Base &&other) noexcept
{
    std::cout << "Base move constructor call\n";
}

#endif //INC_18_BASE_H
