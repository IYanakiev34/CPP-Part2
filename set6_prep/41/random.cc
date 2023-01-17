#include "Random.h"

std::mt19937 Random::d_Engine(time(nullptr));
Random::Random(unsigned int low, unsigned int high) : d_Dis(low, high)
{
}
