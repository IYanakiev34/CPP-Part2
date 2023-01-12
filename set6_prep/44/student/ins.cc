#include "student.h"
#include <iostream>

std::ostream &operator<<(std::ostream &out, Student const &obj)
{
    out << obj.d_Name << " " << obj.d_LastName << " " << obj.d_Number << " " << obj.d_Grade << "\n";
    return out;
}