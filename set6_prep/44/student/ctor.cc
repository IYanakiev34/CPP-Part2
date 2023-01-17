#include "student.h"

Student::Student(std::string const &name, std::string const &lastName,
                 unsigned int number, float grade) : d_name(name),
                                                     d_lastName(lastName),
                                                     d_number(number),
                                                     d_grade(grade)
{
}