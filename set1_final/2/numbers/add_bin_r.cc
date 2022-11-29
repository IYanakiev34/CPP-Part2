#include "numbers.ih"

Numbers operator+(Numbers &&tmp, Numbers const &rhs)
{
    return std::move(tmp) += rhs;
}
