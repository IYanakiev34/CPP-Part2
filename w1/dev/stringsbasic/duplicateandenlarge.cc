#include "strings.ih"

string *Strings::duplicateAndEnlarge()
{
    string *ret = new string[d_size + 1];

    for (size_t idx = 0; idx != d_size; ++idx)
        ret[idx] = move(d_str[idx]);

    return ret;
}
