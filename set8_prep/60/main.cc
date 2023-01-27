#include <iostream>
#include <chrono>
#include <string>
#include <future>
#include <thread>

std::string threadFun()
{
    std::cerr << "entry\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cerr << "first cerr\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cerr << "second cerr\n";

    return "end the program";
}

int main(int argc, char **argv)
{
    // 60
    // Start the threadFun in a separate thread
    std::future<std::string> result = std::async(std::launch::async, threadFun);

    size_t count = 0;
    while (true)
    {
        // do the main-task
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cerr << "inspecting: " << ++count << '\n';

        // inspect whether the thread indicates to end the program
        if (result.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
            std::cerr << "done\n";
            break;
        }
    }
    return 0;
}