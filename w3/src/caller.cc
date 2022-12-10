#include "main.ih"

void caller(Base22 &obj)
{
    Derived22 *dp = static_cast<Derived22 *>(&obj);
    dp->hello();
}