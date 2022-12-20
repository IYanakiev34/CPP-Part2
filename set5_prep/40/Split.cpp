#include "Split.h"

Split::Split(int &argc, char **&argv)
        :
        d_argv{argv, argv + argc}
{
    for (size_t idx = 0; idx != argc; ++idx)
    {
        char *token = strtok(argv[idx], " ");
        if (token)
        {
            argv[idx] = token;
            token = strtok(nullptr, " ");
            while (token)
            {
                d_argv.push_back(token);
                token = strtok(nullptr, " ");
            }
        }
    }

    argc = d_argv.size(); // NOLINT (implicit conversion, idk if should cast)
    argv = d_argv.data();
}