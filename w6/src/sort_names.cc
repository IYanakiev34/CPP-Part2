#include "main.ih"

void sortByLastNames(std::vector<Student> &students)
{
    // Sort by names
    std::sort(students.begin(), students.end(), [](Student &a, Student &b) -> bool
              {
                int val = strcasecmp(a.getLastName().c_str(), b.getLastName().c_str()); 
                if (val < 0)
                    return true;
                
                return false; });
}