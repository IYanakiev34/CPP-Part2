#include "TaskThreads.ih"

bool isVowel(char ch)
{
    ch = std::tolower(ch);
    return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
}