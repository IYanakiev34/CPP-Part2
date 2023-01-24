#include "main.ih"

int main(int argc, char **argv)
{
    unsigned const numberOfValues = std::stoull(argv[1]);
    unsigned const lowest = std::stoull(argv[2]);
    unsigned const highest = std::stoull(argv[3]);

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
    FillUnique fillUnique;

    fillUnique.fill(numberOfValues, lowest, highest, randomNumbers);
    std::copy(randomNumbers.begin(), randomNumbers.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}