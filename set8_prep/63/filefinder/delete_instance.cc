#include "FileFinder.ih"

void FileFinder::deleteInstance()
{
    if (s_instance)
    {
        delete s_instance;
        s_instance = nullptr;
    }
}