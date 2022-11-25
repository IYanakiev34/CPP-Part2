#include <iostream>
#include "lib.h"

int main(int argc, char **argv) {
    // Init options
    Options::initialize(argc, argv);

    // Print options
    std::cout << "Options: ";
    for (int ch = 'a'; ch <= 'z'; ++ch) {
        if (Options::instance().option(ch)) {
            std::cout << static_cast<char>(ch) << ' ';
        }
    }
    std::cout << std::endl;

    // Print arguments
    std::cout << "Arguments: ";
    for (size_t idx = 0; idx != Options::instance().nArgs(); ++idx) {
        std::cout << Options::instance()[idx] << ' ';
    }
    std::cout << std::endl;
    return 0;
}
