#include "numbers.ih"

Numbers Numbers::operator-=(Numbers const &tmp) &&
{
    this->subtract(tmp);
    return std::move(*this);
}