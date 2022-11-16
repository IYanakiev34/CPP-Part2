#include "../include/numbers.ih"

Numbers::Numbers(std::size_t size, int *values)
    : d_size(size),
      d_nums(new int[d_size])

{
    // We assume that the size given is the size of the values is that correct?
    for (std::size_t i = 0; i != d_size; ++i)
        d_nums[i] = values[i];
}