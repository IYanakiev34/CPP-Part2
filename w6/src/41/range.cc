#include "Random.h"

std::vector<int> Random::range()
{
    std::vector<int> range;

    for (std::size_t num = d_Dis.min(); num != d_Dis.max(); ++num)
        range.push_back(num);

    return range;
}