#include "main.ih"

Base **derivedFactory(std::size_t size)
{
    Base **bp = new Base *[size];

    for (std::size_t el = 0; el != size; ++el)
        bp[el] = new Derived;

    return bp;
}