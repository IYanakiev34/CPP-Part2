#include "../inc/numbers.ih"

Numbers::Numbers(Numbers &&tmp)
    : d_size(tmp.d_size),
      d_nums(tmp.d_nums)
{
    std::cout << "Move constructor called\n";
    tmp.d_size = 0;
    tmp.d_nums = 0;
}