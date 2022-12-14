#include "derived.h"

void Derived::vHello(std::ostream &out) const
{
    out << d_name << "\n";
}