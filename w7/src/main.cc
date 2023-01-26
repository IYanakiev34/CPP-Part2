#include "main.ih"
struct Lines
{
    int d_lines;

    Lines() : d_lines(0){};
    Lines(Lines &&tmp) : d_lines(tmp.d_lines) { tmp.d_lines = 0; }
};

std::mutex guard;

void consumer(Storage &str, std::ostream &out, Lines &lines)
{
    std::cout << "add: " << &str << "\n";

    while (!str.getFinished())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::lock_guard<std::mutex> lg(guard);
        if (!str.empty())
        {
            out << str.front() << "\n";
            str.pop();
            ++lines.d_lines;
        }
    }
}
int main(int argc, char **argv)
{
    std::vector<std::string> fileNames;

    std::copy(argv + 1, argv + argc, std::back_inserter(fileNames));

    Storage str;
    Lines obj[argc - 1];
    std::ofstream files[argc - 1];
    for (int i = 0; i < argc - 1; ++i)
    {
        files[i] = std::ofstream(fileNames[i]);
        if (!files[i].is_open())
            std::cout << "problem with file: " << fileNames[i];
    }
    std::vector<std::thread> threads;
    int i = 0;
    for (auto it = fileNames.begin(); it != fileNames.end(); ++it)
    {
        threads.push_back(std::thread(consumer, std::ref(str), std::ref(files[i]), std::ref(obj[i])));
        ++i;
    }

    std::string currLine;
    while (getline(std::cin, currLine))
        str.push(currLine);

    str.setFinished(true);

    std::cout << "finished\n";
    for (auto it = threads.begin(); it != threads.end(); ++it)
    {
        if (it->joinable())
            it->join();
    }
    std::cout << "joined\n";

    for (int i = 0; i < argc - 1; ++i)
        std::cout << "Lines[" << i << "]: " << obj[i].d_lines << "\n";

    std::cout << "end\n";
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