#include "consumer.ih"

void Consumer::pollLines(Storage &str, std::string const &filename, std::mutex &mut)
{
    std::ofstream out(filename);
    if (!out.is_open())
        std::cerr << "Cannot open file\n";

    std::cout << "Address of storage: " << &str << "\n";

    while (!str.getFinished())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::lock_guard<std::mutex> lg(mut);
        if (!str.empty())
        {
            out << str.front() << "\n";
            str.pop();
            ++d_lines;
        }
    }
}