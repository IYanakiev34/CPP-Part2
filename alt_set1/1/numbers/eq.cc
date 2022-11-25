#include "numbers.ih"

bool operator==(Numbers const &lhs, Numbers const &rhs)
{
    if (lhs.size() != rhs.size())
        return false;

    for (size_t idx = 0; idx != lhs.size(); ++idx)
    {
        if (lhs[idx] != rhs[idx])
            return false;
    }

    return true;
}
