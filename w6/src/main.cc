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

size_t multiples(std::vector<size_t> const &data)
{
    std::vector<size_t> tmp(data);
    size_t res = 0;

    std::for_each(tmp.begin(), tmp.end(),
                  [&](auto a) mutable
                  {
                      int count = std::count(tmp.begin(), tmp.end(), a);
                      if (count > 1)
                          res += count - 1;
                      tmp.erase(std::remove(tmp.begin(), tmp.end(), a), tmp.end());
                  });
    return res;
}

int main(int argc, char **argv)
{

    // Exercise 41
    /*
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
    */

    // Exercise 42
    /*
    std::sort(argv + 1, argv + argc, [](auto l, auto r)
              { return std::stoi(l) < std::stoi(r); });
    std::copy(argv + 1, argv + argc, std::ostream_iterator<char const *>(std::cout, " "));
    std::cout << "\n";

    std::sort(argv + 1, argv + argc, [](auto l, auto r)
              { return std::stoi(l) > std::stoi(r); });
    std::copy(argv + 1, argv + argc, std::ostream_iterator<char const *>(std::cout, " "));
    std::cout << std::endl;
    */

    // Exercise 43
    /*std::vector<size_t> data{1, 2, 3, 3, 3, 4, 1, 4, 2, 6};

    std::cout << multiples(data) << " multiples were found\n";
    */

    // Exercise 47
    /*
    IotaWrapper wrap(0, [](unsigned const &n)
                     { return n + 2; });
    std::vector<unsigned> n(10);
    std::iota(n.begin(), n.end(), wrap);
    std::copy(n.begin(), n.end(), std::ostream_iterator<unsigned>(std::cout, " "));
    std::cout << std::endl;
    */

    // Exercise 44
    /*
    std::vector<Student> students;
    if (argc < 2)
    {
        usage();
        return 1;
    }
    std::string const filename(argv[1]);
    std::ifstream file(filename);

    if (!file.is_open())
        std::cerr << "Couldn't open the file: " << filename << "\n";

    // Read students from file
    read(file, students);

    // Sort by last name
    sortByLastNames(students);

    // Put indcies into indices vector
    std::vector<int> indices = createIndices(students);

    // Sort by number
    sortByNumber(students, indices);

    // Write sorted by names
    std::cout << "Sorted by last names\n";
    writeNames(std::cout, students);
    std::cout << "\n";

    // Write sorted by numbers
    std::cout << "Sorted by numbers\n";
    writeNrs(std::cout, students, indices);
    std::cout << std::endl;
    */
}
