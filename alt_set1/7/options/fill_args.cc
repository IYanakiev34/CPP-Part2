#include "options.ih"

void Options::fillArgs(size_t argc, char **argv) {
    d_nArgs = argc - 1 - d_options.length();    // # arguments: argv[0]
    // doesn't count,
    // d_options.length() are the
    // # options

    d_args = d_nArgs == 0 ? 0 : new std::string[d_nArgs];    // room for the args

    for (size_t idx = 1, argIdx = 0; idx != argc; ++idx)    // find the args
    {
        if (argv[idx][0] != '-')                            // got an argument
            d_args[argIdx++] = argv[idx];                   // store it.
    }
}