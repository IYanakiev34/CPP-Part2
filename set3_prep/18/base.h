#ifndef BASE_H
#define BASE_H

#include <iostream>
class Base
{
public:
    // Following methods define in the header file for simplicity
    Base()
    {
        std::cout << "Base default constructor\n";
    }
    ~Base() = default;
    Base(Base const &other)
    {
        std::cout << "Base copy called\n";
    }

    Base(Base &&tmp)
    {
        std::cout << "Base move called\n";
    }
};

#endif