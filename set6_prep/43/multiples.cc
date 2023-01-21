#include "main.ih"

size_t multiples(std::vector<size_t> const &data)
{
    std::vector<size_t> uniqueData;
    std::unique_copy(data.begin(), data.end(),
                     std::back_inserter(uniqueData));
    return data.size() - uniqueData.size();
}