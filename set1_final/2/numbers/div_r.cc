#include "numbers.ih"

Numbers Numbers::operator/=(int rhs) &&
{
    this->div(rhs);
    return std::move(*this);
}