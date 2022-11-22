#include "numbers.ih"

bool operator==(Numbers const &lhs, Numbers const &rhs)
{
    if (lhs.getSize() != rhs.getSize())
        return false;

    for (int i = 0; i != lhs.getSize(); ++i)
    {
        if (lhs[i] != rhs[i])
            return false;
    }

    return true;
}