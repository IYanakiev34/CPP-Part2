#include "main.ih"

int main(int argc, char **argv)
{
    std::vector<size_t> data{1, 2, 3, 4, 3, 4, 5, 23, 5, 56, 1, 2, 3};

    std::cout << multiples(data) << " multiples were found\n";
}