#include "options.ih"

void Options::fillOptions(size_t argc, char **argv) {
    for (size_t idx = 1; idx != argc; ++idx)        // visit all arguments
    {
        if (*argv[idx] == '-')                      // if it's an option:
            d_options += argv[idx][1];              // add the option char
    }
}