#include "numbers.ih"

void Numbers::mult(int rhs)
{
    for (std::size_t i = 0; i != this->d_size; ++i)
        this->d_nums[i] *= rhs;
}