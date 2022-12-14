#ifndef DERIVED26_H
#define DERIVED26_H

#include "base26.h"
#include <string>

class Derived : public Base
{
    std::string d_name;

public:
    Derived();
    ~Derived() override;

private:
    void vHello(std::ostream &out) override;
};
#endif