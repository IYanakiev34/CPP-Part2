#ifndef BASE26_H
#define BASE26_H

#include <iosfwd>
class Base
{
public:
    Base() = default;
    virtual ~Base();

    void hello(std::ostream &out);

private:
    virtual void vHello(std::ostream &out);
};

#endif