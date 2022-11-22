#include "numbers.ih"

Numbers::Numbers(Numbers const &other)
    : d_size(other.d_size),
      d_nums(new int[d_size])
{
    std::cout << "Copy constructor called\n";
    for (std::size_t i = 0; i != d_size; ++i)
        d_nums[i] = other[i];
}