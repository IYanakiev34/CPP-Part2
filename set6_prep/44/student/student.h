#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iosfwd>

class Student
{
    std::string d_name;
    std::string d_lastName;
    unsigned int d_number;
    float d_grade;

public:
    Student() = default;

    Student(std::string const &name, std::string const &lastName,
            unsigned int number, float grade);

    std::string name() const;

    std::string lastName() const;

    unsigned int number() const;

    float grade() const;

    friend std::istream &operator>>(std::istream &in, Student &obj);

    friend std::ostream &operator<<(std::ostream &out, Student const &obj);
};

inline std::string Student::name() const
{
    return d_name;
}

inline std::string Student::lastName() const
{
    return d_lastName;
}

inline unsigned int Student::number() const
{
    return d_number;
}

inline float Student::grade() const
{
    return d_grade;
}

#endif