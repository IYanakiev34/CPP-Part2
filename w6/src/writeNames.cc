#include "main.ih"

void writeNames(std::ostream &out, std::vector<Student> &students)
{
    for (auto it = students.begin(); it != students.end(); ++it)
        out << *it;
}