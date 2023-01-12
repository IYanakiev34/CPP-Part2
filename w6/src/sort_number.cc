#include "main.ih"

void sortByNumber(std::vector<Student> &students, std::vector<int> &indices)
{
    std::sort(indices.begin(), indices.end(), [&](int const &a, int const &b) -> bool
              {
        if (students[a].getNumber() < students[b].getNumber())
            return true;
        return false; });
}