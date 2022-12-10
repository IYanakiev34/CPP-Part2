#ifndef INC_20_STRINGREPEAT_H
#define INC_20_STRINGREPEAT_H

#include <string>

class StringRepeat : public std::string
{
public:
    StringRepeat(size_t count, std::string const &str);
};


#endif //INC_20_STRINGREPEAT_H
