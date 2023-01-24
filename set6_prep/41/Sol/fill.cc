#include "FillUnique.ih"

void FillUnique::fill(unsigned size, unsigned low, unsigned high,
                      std::vector<int> &vec)
{
    Random random(low, high);
    for (unsigned idx = 0; idx != size; ++idx)
    {
        while (!storeValue(vec, random()))
            ;
    }
}