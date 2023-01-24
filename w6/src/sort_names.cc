#include "main.ih"

void sortByLastNames(std::vector<Student> &students)
{
    // Sort by names
    std::sort(students.begin(), students.end(), [](Student &a, Student &b) -> bool
              { return strcasecmp(a.getLastName().c_str(), b.getLastName().c_str()) < 0; });
}