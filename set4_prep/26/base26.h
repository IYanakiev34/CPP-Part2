#ifndef BASE26_H
#define BASE26_H

#include <iostream>
class Base
{
public:
    Base() = default;
    virtual ~Base()
    {
        std::cout << "Base destructor called\n";
    }

    void hello(std::ostream &out)
    {
        vHello(out);
    }

private:
    virtual void vHello(std::ostream &out)
    {
        out << "Hello from Base\n";
    }
};

#endif