#include "../include/numbers.ih"

Numbers::Numbers(Numbers const &other)
    : d_size(other.d_size),
      d_nums(new int[d_size])
{
    for (std::size_t i = 0; i != d_size; ++i)
        d_nums[i] = other[i];
}