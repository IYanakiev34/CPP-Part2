#include "main.ih"
using namespace std;
bool vowels(char ch, Vstring::CharMap &cmap)
{
    if ("aeiuoAEIOU"s.find(ch) != string::npos) {
        ++cmap[ch];
        return true;
    }
    return false;
}