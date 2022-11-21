#include "../inc/numbers.ih"

Numbers &Numbers::operator+=(Numbers const &other) &
{
    Numbers tmp(*this);
    tmp.add(other);
    swap(tmp);
    return *this;
}