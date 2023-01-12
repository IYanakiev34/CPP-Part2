#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iosfwd>

class Student
{
    std::string d_Name;
    std::string d_LastName;
    unsigned int d_Number;
    float d_Grade;

public:
    Student() = default;
    Student(std::string const &name, std::string const &lastName, unsigned int number, float grade);

    std::string getName();
    std::string getLastName();
    unsigned int getNumber();
    float getGrade();

    friend std::istream &operator>>(std::istream &in, Student &obj);
    friend std::ostream &operator<<(std::ostream &out, Student const &obj);
};

inline std::string Student::getName()
{
    return d_Name;
}

inline std::string Student::getLastName()
{
    return d_LastName;
}

inline unsigned int Student::getNumber()
{
    return d_Number;
}

inline float Student::getGrade()
{
    return d_Grade;
}
#endif