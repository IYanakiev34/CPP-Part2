#include "numbers.ih"

Numbers &Numbers::operator-=(Numbers const &other) &
{
    Numbers copy(*this);
    copy.subtract(other);
    swap(copy);
    return *this;
}