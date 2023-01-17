#include "FillUnique.h"
#include "Random.h"

void FillUnique::fill(unsigned int size, unsigned int low, unsigned int high,
                      std::vector<int> &vec)
{
    Random random(low, high);
    for (unsigned int idx = 0; idx != size; ++idx)
        storeValue(vec, random());
}