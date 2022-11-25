#include "numbers.ih"

Numbers::Numbers(std::size_t size, int value)
    : d_size(size),
      d_nums(new int[d_size])
{
    for (std::size_t idx = 0; idx != d_size; ++idx)
        d_nums[idx] = value;
}