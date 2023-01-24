#include "TaskThreads.ih"

bool isPunctuation(char ch)
{
    if (std::isspace(ch))
        return false;
    return not std::isalnum(ch);
}