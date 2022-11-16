#include "../inc/numbers.ih"

Numbers::Numbers(std::size_t size)
    : d_size(size),
      d_nums(new int[d_size])
{
    for (std::size_t i = 0; i != d_size; ++i)
        d_nums[i] = 0;
}