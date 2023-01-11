#ifndef INCLUDED_STRINGS_H
#define INCLUDED_STRINGS_H

#include <string>
#include <vector>

class Strings
{
    std::vector<std::string> d_str;

public:
    Strings();
    Strings(std::size_t size);
    Strings(std::size_t size, std::string const &word);
    std::size_t size();
    std::size_t capacity();

    void resize(std::size_t newSize);
    void reserve(std::size_t reserveSpace);
    std::string &at(std::size_t idx);

    Strings &operator+=(std::string const &string);
    std::string &operator[](std::size_t idx);
    std::string const &operator[](std::size_t idx) const;
};

inline std::size_t Strings::size()
{
    return d_str.size();
}

inline std::size_t Strings::capacity()
{
    return d_str.capacity();
}

inline void Strings::resize(std::size_t newSize)
{
    d_str.resize(newSize);
}

inline void Strings::reserve(std::size_t reserveSpace)
{
    d_str.reserve(reserveSpace);
}

inline std::string &Strings::operator[](std::size_t idx)
{
    return d_str[idx];
}

inline std::string const &Strings::operator[](std::size_t idx) const
{
    return d_str[idx];
}
#endif
