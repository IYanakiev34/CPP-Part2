#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base
{
public:
    Base() = default;
    virtual ~Base(); // made this a suitable base class
    void hello(std::ostream &out); // inlined this

private:
    virtual void vHello(std::ostream &out); // moved def to base_vhello.cc
};

inline void Base::hello(std::ostream &out)
{
    vHello(out);
}

#endif
