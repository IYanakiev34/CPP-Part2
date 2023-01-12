#include "student.h"
#include <iostream>
#include <string>

std::istream &operator>>(std::istream &in, Student &obj)
{
    in >> obj.d_Name >> obj.d_LastName >> obj.d_Number >> obj.d_Grade;
    return in;
}