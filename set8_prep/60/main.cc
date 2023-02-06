#include "main.ih"

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