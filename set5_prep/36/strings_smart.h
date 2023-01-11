#ifndef STRINGS_SMART_H
#define STRINGS_SMART_H

#include <vector>
#include <memory>
#include <string>

class SmartStrings
{
    std::vector<std::shared_ptr<std::string>> d_str;

public:
    SmartStrings();
    SmartStrings(std::size_t size);
    SmartStrings(std::size_t size, std::string const &word);
    std::size_t size();
    std::size_t capacity();

    void resize(std::size_t newSize);
    void reserve(std::size_t reserveSpace);
    std::shared_ptr<std::string> &at(std::size_t idx);

    SmartStrings &operator+=(std::string const &string);
    std::string &operator[](std::size_t idx);
    std::string const &operator[](std::size_t idx) const;
};

inline std::size_t SmartStrings::size()
{
    return d_str.size();
}

inline std::size_t SmartStrings::capacity()
{
    return d_str.capacity();
}

inline void SmartStrings::resize(std::size_t newSize)
{
    d_str.resize(newSize);
}

inline void SmartStrings::reserve(std::size_t reserveSpace)
{
    d_str.reserve(reserveSpace);
}

inline std::string &SmartStrings::operator[](std::size_t idx)
{
    return *d_str[idx];
}
inline std::string const &SmartStrings::operator[](std::size_t idx) const
{
    return *d_str[idx];
}
#endif