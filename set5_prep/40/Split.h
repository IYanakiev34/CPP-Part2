#include <cstring>
#include <vector>

class Split
{
    std::vector<char *> d_argv;
public:
    Split(int &argc, char **&argv);
};
