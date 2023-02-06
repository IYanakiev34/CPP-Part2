#include "FileFinder.h"
#include "FileFinder.ih"

std::vector<std::string> FileFinder::getPathsFromDir(std::string const dirName)
{
    std::vector<std::string> sourceFiles;

    for (auto const &entry : std::filesystem::recursive_directory_iterator(dirName))
    {
        if (entry.is_regular_file())
        {
            std::string fileName = entry.path().string();
            std::string ext = fileName.substr(fileName.find_last_of(".") + 1);
            if (checkExtension(ext))
                sourceFiles.push_back(fileName);
        }
    }

    return sourceFiles;
}
