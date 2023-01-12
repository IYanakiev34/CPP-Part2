#include "FillUnique.h"
#include "Random.h"
#include <iostream>

void FillUnique::fill(unsigned int s, unsigned int l, unsigned int h, std::vector<int> &vec)
{
    Random r(l, h);
    for (int idx = 0; idx != s; ++idx)
        storeValue(vec, r());
}