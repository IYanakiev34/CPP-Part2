#ifndef BASE_H
#define BASE_H

class Base
{
public:
    Base();
    Base(Base const &base);
    Base(Base &&tmp);
    ~Base();
};

#endif