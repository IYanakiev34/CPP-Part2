#include "../inc/numbers.ih"

Numbers operator/(Numbers const &lhs, int rhs)
{
    Numbers copy(lhs);
    return std::move(copy) / rhs;
}