#ifndef FILLUNIQUE_H
#define FILLUNIQUE_H

#include <vector>

class FillUnique
{
public:
    void fill(unsigned size, unsigned low, unsigned high,
              std::vector<int> &vec);

private:
    bool storeValue(std::vector<int> &vec, int val);
};

#endif