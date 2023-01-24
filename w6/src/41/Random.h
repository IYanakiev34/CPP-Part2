#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
#include <random>

class Random
{
    static std::mt19937 d_Engine;
    std::uniform_int_distribution<int> d_Dis;

public:
    Random(unsigned low, unsigned high);
    std::pair<int, int> range();
    int operator()();
};

inline int Random::operator()()
{
    return d_Dis(d_Engine);
}

inline std::pair<int, int> Random::range()
{
    return {d_Dis.min(), d_Dis.max()};
}
#endif