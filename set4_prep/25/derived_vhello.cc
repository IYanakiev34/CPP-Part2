#include "derived.h"

void Derived::vHello(std::ostream &out)
{
    out << d_name << "\n";
}