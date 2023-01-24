#include "main.ih"

void sortByLastNames(std::vector<Student> &students)
{
    // Sort by names
    std::sort(students.begin(), students.end(),
              [](Student &student1, Student &student2) -> bool
              {
                  return (strcasecmp(student1.lastName().c_str(), student2.lastName().c_str())) < 0;
              });
}
