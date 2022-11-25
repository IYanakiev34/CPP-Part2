#include <iostream>
#include "lib.h"

int main() {
    /*
     * Test the Options class
     */

    // initialize the options
    Options::initialize(1, new char*[1]{"-z"});//, "-a"});//, "-b"});//, "-d"});

    return 0;
}
