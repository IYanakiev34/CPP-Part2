#ifndef FILE_FINDER_H
#define FILE_FINDER_H

#include <vector>
#include <string>

class FileFinder
{
public:
    static FileFinder *getInstance();
    static void deleteInstance();

    std::vector<std::string> getSourcesFromFile(std::string const &fileName);
    std::vector<std::string> getSourcesFromDir(std::string const &dirName);
    std::vector<std::string> getSourcesFromDirRec(std::string const &dirName);

private:
    static FileFinder *s_instance;
    FileFinder();
    FileFinder(FileFinder const &other) = delete;
    FileFinder &operator=(FileFinder const &other) = delete;

    // could be extended to support user input of vector of types to check
    // not needed for this program though
    bool checkExtension(std::string const &ext);
};

#endif