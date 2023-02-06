#include "main.ih"
#include "63/FileFinder.h"

void printSources(std::vector<std::string> &sources)
{
    for (auto &source : sources)
        std::cout << source << "\n";
}

void testFileFinder()
{
    std::vector<std::string> names = FileFinder::getPathsFromDir("../src/");
    printSources(names);
}

int main(int argc, char **argv)
{

    CompileFlag cp;

    if (argc == 2)
        cp.setThreadNum(std::stoul(argv[1]));
    else if (argc == 3)
    {
        cp.setThreadNum(std::stoul(argv[1]));
        cp.setTempDir(argv[2]);
    }
    
    // TODO: fix the hardcoded dir and added it like a flag passed to the program
    std::vector<std::string> sources = FileFinder::getPathsFromDir("../src/");
    printSources(sources);
    
        
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
