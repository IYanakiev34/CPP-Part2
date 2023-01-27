#include "main.ih"

void createThreads(std::vector<Consumer> &threads, std::vector<std::string> &filenames,
                   Storage &str, std::mutex &mut)
{
    for (auto it = filenames.begin(); it != filenames.end(); ++it)
        threads.push_back(Consumer(str, *it, mut));
}