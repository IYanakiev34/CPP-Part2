#include "numbers.ih"

Numbers::Numbers(std::initializer_list<int> iniList)
    : d_size(iniList.size()),
      d_nums(new int[d_size])
{
    for (std::size_t idx = 0; idx != d_size; ++idx)
        d_nums[idx] = *(iniList.begin() + idx);
}