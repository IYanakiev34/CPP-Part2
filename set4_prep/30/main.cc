#include "main.ih"

int main(int argc, char **argv)
{
    std::ofstream one("one");
    std::ofstream two("two");

    BiStream ms(one, two);

    ms << "Hello world" << std::endl;

    // Output
    // Hello world will be written to the two files
    return 0;
}