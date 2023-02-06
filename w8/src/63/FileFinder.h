#ifndef FILE_FINDER_H
#define FILE_FINDER_H

#include <vector>
#include <string>

class FileFinder
{
public:
    static std::vector<std::string> getPathsFromDir(std::string const dirName);
private:
    static bool checkExtension(std::string const &ext);
};

#endif
