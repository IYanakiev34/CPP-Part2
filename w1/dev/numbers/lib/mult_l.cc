#include "../inc/numbers.ih"

Numbers &Numbers::operator*=(int rhs) &
{
    this->mult(rhs); // Cannot throw error on multiply os it should be safe to perform op on this object
    return *this;
}