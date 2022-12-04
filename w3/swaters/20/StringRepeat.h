//
// Created by Alex Swaters on 12/4/2022.
//

#ifndef INC_20_STRINGREPEAT_H
#define INC_20_STRINGREPEAT_H

#include <string>

/*
 *  Assume you frequently use the class std::string. Although there is a
 *  constructor string(size_t count, char ch) initializing a string with count
 *  chars there isn't one like string(size_t count, string const &str),
 *  initializing your string with count times str's content.
 *
 *  Solve that problem as follows: create a class that offers all members of
 *  std::string, and whose objects can be used as argument in all cases
 *  where a string parameter is used; be it a value, reference, rvalue
 *  reference or pointer to a string.
 */
class StringRepeat : public std::string
{
public:
    StringRepeat(size_t count, const std::string &str);
};


#endif //INC_20_STRINGREPEAT_H
