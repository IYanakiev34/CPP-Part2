#include "TaskThreads.ih"

bool isHexadecimal(char ch)
{
    if (std::isdigit(ch))
        return true;
    return (ch >= 'a' and ch <= 'f') or (ch >= 'A' and ch <= 'F');
}