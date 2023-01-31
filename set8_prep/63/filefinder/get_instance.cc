#include "FileFinder.ih"

FileFinder *FileFinder::getInstance()
{
    if (!s_instance)
        s_instance = new FileFinder;

    return s_instance;
}