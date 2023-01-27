#include "main.ih"

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
}