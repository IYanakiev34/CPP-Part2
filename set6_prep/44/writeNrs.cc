#include "main.ih"

void writeNrs(std::ostream &out, std::vector<Student> &students, std::vector<int> &indices)
{
    for (auto it = indices.begin(); it != indices.end(); ++it)
        out << students[*it];
}