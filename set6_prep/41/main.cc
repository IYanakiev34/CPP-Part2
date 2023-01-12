#include "main.ih"

void usage()
{
    char const info[] = R"(
        You must enter 3 numbers:
        The amount of random numbers that you wish to generate,
        The lowest number possible
        The highest number possible)";

    std::cout << info << "\n";
}

int main(int argc, char **argv)
{

    // Exercise 41
    unsigned int const numberOfValues = std::stoull(argv[1]);
    unsigned int const lowest = std::stoull(argv[2]);
    unsigned int const highest = std::stoull(argv[3]);

    if (lowest > highest)
    {
        throw "Cannot have a lower bound higher than the highest bound!";
        return 1;
    }

    if ((highest - lowest) < 2 * numberOfValues)
    {
        std::cerr << R"(It will be hard for the system to generate random values,
        increase your range or decrease the quantity)"
                  << std::endl;
    }

    std::vector<int> randomNumbers{};
    FillUnique fU;

    fU.fill(numberOfValues, lowest, highest, randomNumbers);
    std::copy(randomNumbers.begin(), randomNumbers.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}