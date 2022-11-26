#include "numbers.ih"

Numbers &Numbers::operator-=(Numbers const &other) &
{
    this->subtract(other);
    return *this;
}