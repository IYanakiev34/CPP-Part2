#include "main.ih"

enum
{
    ERROR = 1,
};

int usage(char const *const prog)
{
    char const usage_info[] = R"(
    You should input the names of two files with 
    their relative paths regarding the build directory.)";

    std::cout << "Usage: " << prog << "\n\n"
              << usage_info << "\n\n";
    return ERROR;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return usage(argv[0]);

    copyFile(argv[1], argv[2]);
    return 0;
}