#include "main.ih"

std::string threadFun()
{
    std::cerr << "entry\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cerr << "first cerr\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cerr << "second cerr\n";

    return "end the program";
}