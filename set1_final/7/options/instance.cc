#include "options.ih"

Options &Options::instance() {
    if (not s_destructor.optionsAvailable()) {
        std::cerr << "Options::instance() called for a non-initialized object\n";
        exit(1);
    }

    return *s_destructor;
}
