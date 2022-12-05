//
// Created by Alex Swaters on 12/4/2022.
//

#include "StringRepeat.h"

StringRepeat::StringRepeat(size_t count, const std::string &str)
{
    for (size_t idx = 0; idx != count; ++idx)
        append(str);
}
