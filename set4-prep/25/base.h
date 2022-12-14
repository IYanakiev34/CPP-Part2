//JB: 0
#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base
{
    // JB: This class is not suitable as a base class.
public:
    Base() = default;
    void hello(std::ostream &out)
    { //JB: ICI
        vHello(out);
    }

private:
    virtual void vHello(std::ostream &out)
    {
        out << "Hello from base\n";
    }
};
#endif
