#include "../inc/numbers.ih"

Numbers operator/(Numbers &&tmp, int rhs)
{
    return std::move(tmp) /= rhs;
}