#ifndef DERIVED26_H
#define DERIVED26_H

#include "base26.h"
#include <string>

class Derived : public Base
{
    std::string d_name;

public:
    Derived() : d_name("Hello from Derived")
    {
    }
    ~Derived() override
    {
        std::cout << "Derived destructor called\n";
    }

private:
    void vHello(std::ostream &out) override
    {
        out << "Hello from derived\n";
    }
};
#endif