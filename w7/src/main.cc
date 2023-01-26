#include "storage.h"
#include "52/handler.h"

#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
#include <iterator>
#include <thread>
#include <fstream>

#include <queue>

int usage()
{
    char const info[] = R"(You should supply two arguments to the program.
                    The first one should represent the hours,the second one
                    the minutes. Note the two numbers should be positive integral
                    numbers.!)";

    std::cout << info << std::endl;

    return 1;
}

void consumer(Storage &str, std::ostream &out)
{
    while (!str.getFinished())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (!str.empty())
        {
            out << "From thread: " << str.front() << "\n";
            str.pop();
        }
    }
}

int main(int argc, char **argv)
{
    std::string const fileName{argv[1]};
    std::ofstream file{fileName};

    Storage str;
    std::thread thr{consumer, std::ref(str), std::ref(file)};

    // Scan the current line
    std::string currLine;
    while (getline(std::cin, currLine))
        str.push(currLine);

    str.setFinished(true);

    thr.join();
    return 0;
}

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
*/