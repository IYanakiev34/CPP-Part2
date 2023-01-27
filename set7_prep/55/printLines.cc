#include "main.ih"

void printLines(std::vector<Consumer> &threads)
{
    std::for_each(threads.begin(), threads.end(), [](Consumer const &thr)
                  { std::cout << thr.getLines() << "\n"; });
}