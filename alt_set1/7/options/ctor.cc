#include "options.ih"

Options::Options(size_t argc, char **argv) 
{
    fillOptions(argc, argv);
    fillArgs(argc, argv);
}