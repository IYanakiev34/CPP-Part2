#include "main.ih"

void displayDots(bool &isFinished)
{
    while (!isFinished)
    {
        std::cerr << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}