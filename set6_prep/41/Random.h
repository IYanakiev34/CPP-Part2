#ifndef RANDOM_H
#define RANDOM_H

#include <vector>
#include <random>
#include <ctime>

class Random
{
    static std::mt19937 d_Engine;
    std::uniform_int_distribution<int> d_Dis;

public:
    Random(unsigned int low, unsigned int high);
    std::vector<int> range();
    int operator()();
};

inline int Random::operator()()
{
    return d_Dis(d_Engine);
}

#endif