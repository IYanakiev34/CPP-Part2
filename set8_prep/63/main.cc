#include "filefinder/FileFinder.h"

#include <string>
#include <iostream>
#include <thread>

int main(int argc, char **argv)
{
    std::string dir{"."};
    unsigned numThread{};

    // if no args then max threads + current dir
    if (argc < 2)
        numThread = std::thread::hardware_concurrency();

    if (argc == 2) // user defined thread num
    {
        if (std::stoi(argv[1]) == 0)
            numThread = 1;
        else
            numThread = std::stoi(argv[1]);
    }

    if (argc == 3) // user defined dir
    {
        // cod duplication mode it into a function
        if (std::stoi(argv[1]) == 0)
            numThread = 1;
        else
            numThread = std::stoi(argv[1]);

        dir = argv[2];
    }

    FileFinder *fileFinder = FileFinder::getInstance();
    std::vector<std::string> sources = fileFinder->getSourcesFromDirRec(dir);
    std::cout << numThread << '\n';

    // TODO: init blocking queue and workers, then start workers
}

// TODO make a CompileFlag class to store the name of the file that we compile
// also potentially the error output file