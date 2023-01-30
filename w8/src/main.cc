#include "BlockQueue.h"
#include "FileFinder.h"
#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <future>
#include <algorithm>
#include <functional>

#include <iterator>
#include <thread>
#include <cstdlib>

// Should work
void testFileFinderFromDir(std::string const &dir)
{
    FileFinder *finder = FileFinder::getInstance();

    auto files = finder->getSourcesFromDir("../src/");
    std::copy(files.begin(), files.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

void testFileFinderFromDirRec(std::string const &dir)
{
    FileFinder *finder = FileFinder::getInstance();

    auto files = finder->getSourcesFromDirRec("../src/");
    std::copy(files.begin(), files.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}

void printSources(std::vector<std::string> &sources)
{
    for (auto &source : sources)
        std::cout << source << "\n";
}

void compileWorker(std::string const &fileName)
{
    // This should be in a while loop using semaphores
    // for notification when another file is available

    std::string compileCommand{"g++ -std=c++20 -Wall -Werror -o a.out " + fileName};
    // std::string compileCommand{"g++ -std=c++20 -Wall -Werror -o a.out " + fileName + " 2> errors.txt"};
    int res = std::system(compileCommand);
    if (res == 0)
        std::cout << "Successfully compiled file: " << fileName << "\n";
    else
        std::cout << "Error: Could not compile file: " << fileName
                  << ", error output is in errors.txt\n";
    // re-route uoutput to file, return the future of the the filename
    // if  "",no errors if not, errors, main should end
    // print the error in main
    // remove the file
}

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

    std::cout << numThread << std::endl;

    // Start workers one by one
    return 0;
}

// Todo make a CompileFlag class to store the name of the file that we compile
// also potentially the error output file

/**
#include <iostream>
#include <cstdlib>
#include <fstream>

int main() {
  const char* command = "g++ -o test test.cc 2> errors.txt";
  int result = std::system(command);
  if (result == 0) {
    std::cout << "Compilation succeeded!" << std::endl;
  } else {
    std::cout << "Compilation failed with error code " << result << std::endl;
    std::cout << "Error messages:" << std::endl;
    std::ifstream errorFile("errors.txt");
    std::string line;
    while (std::getline(errorFile, line)) {
      std::cout << line << std::endl;
    }
    errorFile.close();
    std::remove("errors.txt");
  }
  return 0;
}
*/