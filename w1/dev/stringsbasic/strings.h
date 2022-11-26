#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <string>

class Strings
{
    size_t d_size = 0;
    std::string *d_str = 0;

public:
    Strings() = default;
    Strings(int argc, char *argv[]); // 2.cc
    Strings(char *environLike[]);    // 3.cc

    Strings(Strings const &other); // see part 1: allocation
    Strings(Strings &&tmp);        // see part 1: allocation

    ~Strings();

    Strings &operator=(Strings const &rhs); // see part 1: allocation
    Strings &operator=(Strings &&rhs);      // see part 1: allocation
    Strings &operator+=(Strings const &other) &;
    Strings operator+=(Strings const &other) &&;

    void swap(Strings &other);

    size_t size() const;

    std::string const &at(size_t idx) const;
    std::string &at(size_t idx);

private:
    std::string *duplicateAndEnlarge();
    void add(std::string const &next); // add another element
};

inline size_t Strings::size() const // potentially dangerous practice:
{                                   // inline accessors
    return d_size;
}

inline std::string const &Strings::at(size_t idx) const
{
    return d_str[idx];
}

inline std::string &Strings::at(size_t idx)
{
    return d_str[idx];
}

#endif
