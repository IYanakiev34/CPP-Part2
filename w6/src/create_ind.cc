#include "main.ih"

std::vector<int> createIndices(std::vector<Student> &students)
{
    std::vector<int> indices(students.size());
    std::iota(indices.begin(), indices.end(), 0);

    return indices;
}