#include "numbers.ih"

Numbers::Numbers(Numbers const &other)
    : d_size(other.d_size),
      d_nums(new int[d_size])
{
    for (std::size_t idx = 0; idx != d_size; ++idx)
        d_nums[idx] = other[idx];
}
