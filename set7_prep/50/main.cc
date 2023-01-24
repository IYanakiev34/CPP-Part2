#include <iostream>
#include <chrono>

int usage()
{
    char const info[] = R"(You should supply two arguments to the program.
                    The first one should represent the hours,the second one
                    the minutes. Note the two numbers should be positive integral
                    numbers.!)";

    std::cout << info << std::endl;

    return 1;
}

int main(int argc, char **argv)
{
    /* Exercise 50
     */
    if (argc < 3)
        return usage();

    unsigned const hours = std::stoull(argv[1]);
    unsigned const seconds = std::stoull(argv[2]);

    std::cout << "Hours: " << hours << ", to minutes: "
              << std::chrono::duration_cast<std::chrono::minutes>(std::chrono::hours(hours)).count() << "\n";
    std::cout << "Seconds " << seconds << ",to minutes: "
              << std::chrono::duration_cast<std::chrono::minutes>(std::chrono::seconds(seconds)).count() << "\n";

    std::cout << "\nIf you wish to get precise minutes in the form of double\n";
    std::cout << "Seconds: " << seconds << ", to precise minutes: "
              << std::chrono::duration<double, std::ratio<60, 1>>(std::chrono::seconds(seconds)).count()
              << std::endl;
    return 0;
}