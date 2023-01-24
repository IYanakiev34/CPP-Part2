#include "FillUnique.ih"

bool FillUnique::storeValue(std::vector<int> &vec, int val)
{
    auto it = std::find(vec.begin(), vec.end(), val);

    if (it != vec.end())
        return false;

    vec.push_back(val);
    return true;
}