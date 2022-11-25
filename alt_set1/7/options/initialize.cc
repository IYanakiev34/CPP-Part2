#include "options.ih"

Options &Options::initialize(size_t argc, char **argv) {
    if (s_destructor.optionsAvailable()) {
        std::cerr << "Options::initialize() called: already initialized\n";
        exit(1);
    }

    s_destructor = new Options{argc, argv};

    return *s_destructor;
}