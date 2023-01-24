#include "52/handler.h"

#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <iterator>
#include <thread>
#include <fstream>

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

    if (argc < 3)
        return usage();

    unsigned hours = std::stoull(argv[1]);
    unsigned seconds = std::stoull(argv[2]);

    std::cout << "Hours: " << hours << ", to minutes: "
              << std::chrono::duration_cast<std::chrono::minutes>(std::chrono::hours(hours)).count() << "\n";
    std::cout << "Seconds " << seconds << ",to minutes: "
              << std::chrono::duration_cast<std::chrono::minutes>(std::chrono::seconds(seconds)).count() << "\n";

    std::cout << "\nIf you wish to get precise minutes in the form of double\n";
    std::cout << "Seconds: " << seconds << ", to precise minutes: "
              << std::chrono::duration<double, std::ratio<60, 1>>(std::chrono::seconds(seconds)).count()
              << std::endl;
    */

    /* Exercise 52
     */

    if (argc < 3)
        return usage();

    std::string const fileName{argv[1]};
    std::string const text{argv[2]};

    Handler h{};
    std::ofstream of{fileName};

    if (!of.is_open())
    {
        std::cerr << "Could not open the file\n";
        return 1;
    }

    std::thread thr{&Handler::shift, &h, std::ref(of), std::ref(text)};
    thr.join();

    std::cout << "\nSecond method\n";
    // I am not sure by what a second thread defines an object means
    // Does it mean that we make a thread which returns a Handler object
    // and then pass this object into another thread?
    // What does a thread that defines an object mean

    // Im going with my best guess
    std::thread t{&Handler::shift, Handler{}, std::ref(of), std::ref(text)};
    t.join();
    return 0;
}