#include "lib.h"
#include <iostream>

Options::Destructor Options::s_destructor;

Options::Options(size_t argc, char **argv) {
    fillOptions(argc, argv);
    fillArgs(argc, argv);
}

void Options::fillOptions(size_t argc, char **argv) {
    for (size_t idx = 1; idx != argc; ++idx)        // visit all arguments
    {
        if (*argv[idx] == '-')                      // if it's an option:
            d_options += argv[idx][1];              // add the option char
    }
}

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

Options &Options::initialize(size_t argc, char **argv) {
    if (s_destructor.optionsAvailable()) {
        std::cerr << "Options::initialize() called: already initialized\n";
        exit(1);
    }

    s_destructor = new Options{argc, argv};

    return *s_destructor;
}

// static
Options &Options::instance() {
    if (not s_destructor.optionsAvailable()) {
        std::cerr << "Options::instance() called for a non-initialized object\n";
        exit(1);
    }

    return *s_destructor;
}

std::string const &Options::operator[](size_t idx) const {
    if (idx >= d_nArgs) {
        std::cerr << "Options::operator[]: index out of range\n";
        exit(1);
    }

    return d_args[idx];
}
