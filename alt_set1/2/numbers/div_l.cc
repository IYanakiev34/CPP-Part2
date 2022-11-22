#include "numbers.ih"

Numbers &Numbers::operator/=(int rhs) &
{
    Numbers copy(*this);
    copy.div(rhs);
    swap(copy);
    return *this;
}