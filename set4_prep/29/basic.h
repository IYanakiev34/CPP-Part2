#ifndef BASIC_H
#define BASIC_H

// Definitions in header for brievity
#include <iostream>
class Basic
{
public:
    Basic()
    {
        std::cout << "Basic constructor called\n";
    }
    Basic(int val)
    {
        std::cout << "Basic constructor called with value: " << val << "\n";
    }
};

#endif