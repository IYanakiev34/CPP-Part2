#include "main.ih"

void read(std::istream &in, std::vector<Student> &data)
{
    Student currStudent;

    while (in >> currStudent)
        data.push_back(currStudent);
}