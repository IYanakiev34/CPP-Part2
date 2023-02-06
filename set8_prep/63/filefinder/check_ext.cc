#include "FileFinder.ih"

bool FileFinder::checkExtension(std::string const &ext)
{
    if (ext == "cpp" || ext == "cc")
        return true;
    return false;
}