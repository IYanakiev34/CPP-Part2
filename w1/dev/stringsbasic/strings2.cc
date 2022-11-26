#include "strings.ih"

Strings::Strings(int argc, char **argv)
:
    d_size(argc),
    d_str(new string[argc])
{
    for (size_t idx = 0, end = argc; idx != end; ++idx)
        d_str[idx] = argv[idx];
}
