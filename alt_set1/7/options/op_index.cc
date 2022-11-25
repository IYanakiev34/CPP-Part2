#include "options.ih"

std::string const &Options::operator[](size_t idx) const {
    if (idx >= d_nArgs) {
        std::cerr << "Options::operator[]: index out of range\n";
        exit(1);
    }

    return d_args[idx];
}