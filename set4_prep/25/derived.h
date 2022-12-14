#ifndef DERIVED_H
#define DERIVED_H

#include "base.h"
#include <string>

class Derived : public Base
{
    std::string d_name;

public:
    Derived(std::string &name) : d_name(name)
    {
    }

private:
    void vHello(std::ostream &out) override; // moved to derived_vhello.cc
};
#endif