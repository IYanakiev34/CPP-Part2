#include "student.h"
#include <iostream>
#include <string>

std::istream &operator>>(std::istream &in, Student &obj)
{
    in >> obj.d_name >> obj.d_lastName >> obj.d_number >> obj.d_grade;
    return in;
}