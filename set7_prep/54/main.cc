#include "main.ih"

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

    // join the thread
    thr.join();
}