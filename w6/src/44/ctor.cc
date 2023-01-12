#include "student.h"

Student::Student(std::string const &name, std::string const &lastName, unsigned int number, float grade) : d_Name(name),
                                                                                                           d_LastName(lastName),
                                                                                                           d_Number(number),
                                                                                                           d_Grade(grade)
{
}