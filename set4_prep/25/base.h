#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base
{
public:
    Base() = default;
    void hello(std::ostream &out)
    {
        vHello(out);
    }

private:
    virtual void vHello(std::ostream &out)
    {
        out << "Hello from base\n";
    }
};
#endif