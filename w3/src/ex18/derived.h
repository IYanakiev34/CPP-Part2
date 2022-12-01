#ifndef DERIVED_H
#define DERIVED_H

class Derived : public Base
{
public:
    Derived();
    Derived(Derived const &other);
    Derived(Derived &&tmp);
    ~Derived();
};

#endif