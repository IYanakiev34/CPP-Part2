#include "student.h"
#include <iostream>

std::ostream &operator<<(std::ostream &out, Student const &obj)
{
    out << obj.d_name << " " << obj.d_lastName << " " << obj.d_number << " "
        << obj.d_grade << "\n";
    return out;
}