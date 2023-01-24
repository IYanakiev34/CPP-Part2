#include "Random.ih"

std::mt19937 Random::d_Engine(time(nullptr));