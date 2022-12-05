#include "string_rep.h"

StringRep::StringRep(std::size_t count, std::string const &other)
{
    for (std::size_t i = 0; i != count; ++i)
        append(other);
}