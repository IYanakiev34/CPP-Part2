#include "numbers.ih"

Numbers::Numbers(std::size_t size, int *values)
    : d_size(size),
      d_nums(new int[d_size])

{
    // We assume that the size given is the size of the values is that correct?
    //JB: The size is the number of values.
    for (std::size_t idx = 0; idx != d_size; ++idx)
        d_nums[idx] = values[idx];
}
