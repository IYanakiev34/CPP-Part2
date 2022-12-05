#ifndef STRING_REP_H
#define STRING_REP_H

#include <string>

class StringRep : public std::string
{

public:
    StringRep(std::size_t count, std::string const &other);
};

#endif