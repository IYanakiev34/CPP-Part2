#ifndef INC_21_STRING_H
#define INC_21_STRING_H

#include <string>

class String : public std::string
{
public:
    String &insert(std::string const &txt);

private:
    friend bool operator==(String const &lhs, String const &rhs);

    friend bool operator<(String const &lhs, String const &rhs);
};

inline String &String::insert(std::string const &txt)
{
    std::string::insert(0, txt);
    return *this;
}

inline bool operator==(String const &lhs, String const &rhs)
{
    return static_cast<std::string>(lhs) == static_cast<std::string>(rhs);
}

inline bool operator<(String const &lhs, String const &rhs)
{
    return static_cast<std::string>(lhs) < static_cast<std::string>(rhs);
}

#endif //INC_21_STRING_H
