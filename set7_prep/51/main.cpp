#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
        throw invalid_argument{"Missing argument"};
    int timeValue = atoi(argv[1]);
    char timeUnit = argv[1][strlen(argv[1]) - 1];

    auto now = chrono::system_clock::now();
    time_t nowC = chrono::system_clock::to_time_t(now);
    cout << "Actual time:\n"
        << "Local time: " << put_time(localtime(&nowC), "%c") << '\n'
        << "UTC time: " << put_time(gmtime(&nowC), "%c") << '\n';

    switch (timeUnit)
    {
        case 's':
            now += chrono::seconds(timeValue);
            break;
        case 'm':
            now += chrono::minutes(timeValue);
            break;
        case 'h':
            now += chrono::hours(timeValue);
            break;
        default:
            throw invalid_argument{"Invalid time unit"};
    }
    nowC = chrono::system_clock::to_time_t(now);
    cout << "After adding " << argv[1] << ":\n"
        << "Local time: " << put_time(localtime(&nowC), "%c") << '\n'
        << "UTC time: " << put_time(gmtime(&nowC), "%c") << '\n';
}
