#ifndef FILLUNIQUE_H
#define FILLUNIQUE_H

#include "Random.h"
#include <vector>

class FillUnique
{
public:
    void fill(unsigned int size, unsigned int low, unsigned int high,
              std::vector<int> &vec);

private:
    void storeValue(std::vector<int> &vec, int val);
};

#endif