#include "Base.h"
#include "Derived.h"

Base **derivedFactory(size_t size)
{
    Base **derived = new Base *[size];
    for (size_t i = 0; i != size; ++i)
        derived[i] = new Derived;
    return derived;
}

int main()
{
    size_t size = 10;
    Base **bp = derivedFactory(size);
    for (size_t idx = 0; idx != size; ++idx)
        delete bp[idx];
    delete[] bp;
}
