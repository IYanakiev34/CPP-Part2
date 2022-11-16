#include "../include/numbers.ih"

Numbers::Numbers(std::initializer_list<int> iniList)
    : d_size(iniList.size()),
      d_nums(new int[d_size])
{
    for (std::size_t i = 0; i != d_size; ++i)
        d_nums[i] = *(iniList.begin() + i);
}