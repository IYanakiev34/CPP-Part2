#include "main.ih"

int main(int argc, char **argv)
{
    std::ofstream one("one.txt");
    std::ofstream two("two.txt");

    BiStream ms(one, two);

    ms << "Hello World" << std::endl;

    return 0;
}