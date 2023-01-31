#include "FileFinder.ih"

std::vector<std::string> FileFinder::getSourcesFromDir(std::string const &dir)
{
    std::vector<std::string> sourceFiles;

    for (auto const &entry : std::filesystem::directory_iterator(dir))
    {
        if (entry.is_regular_file())
        {
            std::string fileName = entry.path().string();
            std::string extension = fileName.substr(fileName.find_last_of(".") + 1);
            if (checkExtension(extension))
                sourceFiles.push_back(fileName);
        }
    }
    return sourceFiles;
}