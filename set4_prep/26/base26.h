#ifndef BASE26_H
#define BASE26_H

#include <iostream>

class Base
{
public:
    Base() = default;
    virtual ~Base();
    void hello(std::ostream &out);

private:
    virtual void vHello(std::ostream &out);
};

inline void Base::hello(std::ostream &out)
{
    vHello(out);
}

#endif
