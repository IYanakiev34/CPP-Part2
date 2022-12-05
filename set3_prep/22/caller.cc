#include "main.ih"

void caller(Base22 &obj)
{
    Derived22 d = static_cast<Derived22 &>(obj);
    d.hello();
}