#include "numbers.ih"

Numbers &Numbers::operator+=(Numbers const &other) &
{
    this->add(other);
    return *this;
}