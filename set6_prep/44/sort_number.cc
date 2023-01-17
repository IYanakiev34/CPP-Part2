#include "main.ih"

void sortByNumber(std::vector<Student> &students, std::vector<int> &indices)
{
    std::sort(indices.begin(), indices.end(),
              [&](int const &idx1, int const &idx2) -> bool
              {
                  if (students[idx1].number() < students[idx2].number())
                      return true;
                  return false;
              });
}