#include "numbers.ih"

Numbers Numbers::operator*=(int rhs) &&
{
    this->mult(rhs);
    return std::move(*this);
}