#include "numbers.ih"

Numbers operator+(Numbers const &lhs, Numbers const &rhs)
{
    // Used to safely move the resources of the copy and reuse existing functionality
    // of the + assignment with &&,&
    Numbers tmp(lhs);
    return std::move(tmp) + rhs;
}