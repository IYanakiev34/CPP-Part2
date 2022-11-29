#include "numbers.ih"

Numbers operator-(Numbers const &lhs, Numbers const &rhs)
{
    Numbers copy(lhs);
    return std::move(copy) -= rhs;
}