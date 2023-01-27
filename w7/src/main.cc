#include "main.ih"

void createThreads(std::vector<Consumer> &threads, std::vector<std::string> &filenames,
                   Storage &str, std::mutex &mut)
{
    for (auto it = filenames.begin(); it != filenames.end(); ++it)
        threads.push_back(Consumer(str, *it, mut));
}

void startThreads(std::vector<Consumer> &threads)
{
    std::for_each(threads.begin(), threads.end(), [](Consumer &thr)
                  { thr.startThread(); });
}

void joinThreads(std::vector<Consumer> &threads)
{
    std::for_each(threads.begin(), threads.end(), [](Consumer &thr)
                  { thr.joinThread(); });
}

void printLines(std::vector<Consumer> &threads)
{
    std::for_each(threads.begin(), threads.end(), [](Consumer const &thr)
                  { std::cout << thr.getLines() << "\n"; });
}

int main(int argc, char **argv)
{
    std::vector<std::string> fileNames;
    std::copy(argv + 1, argv + argc, std::back_inserter(fileNames));

    Storage str;
    std::mutex mut;
    std::vector<Consumer> consumers;

    createThreads(consumers, fileNames, str, mut);

    startThreads(consumers);

    // Start the producer
    std::string currLine;
    while (getline(std::cin, currLine))
        str.push(currLine);

    // Finish the producer
    str.setFinished(true);

    joinThreads(consumers);

    printLines(consumers);
    return 0;
}
/*54
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
*/

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