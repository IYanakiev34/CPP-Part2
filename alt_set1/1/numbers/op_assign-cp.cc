#include "numbers.ih"

Numbers &Numbers::operator=(Numbers const &other)
{
    // guard if assigning to self
    if (*this != other)
    {
        Numbers copy(other);
        swap(copy);
    }
    return *this;
}