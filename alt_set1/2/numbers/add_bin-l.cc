#include "numbers.ih"

Numbers operator+(Numbers const &lhs, Numbers const &rhs)
{
    Numbers tmp(lhs);
    return std::move(tmp) + rhs;
}