#include "../inc/numbers.ih"

Numbers operator*(Numbers const &lhs, int rhs)
{
    Numbers tmp(lhs);
    return std::move(tmp) * rhs;
}