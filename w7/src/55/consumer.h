#ifndef CONSUMER_THREAD_H
#define CONUSMER_THREAD_H

class Storage;

#include <thread>
#include <mutex>
#include <string>

class Consumer
{
    std::thread d_thr;
    std::mutex *d_mut;
    Storage *d_str;
    std::string d_filename;
    std::size_t d_lines;

public:
    Consumer(Storage &ref, std::string const &filename, std::mutex &mut);
    Consumer(Consumer &&tmp);

    ~Consumer();

    void startThread();
    void joinThread();
    std::size_t getLines() const;

private:
    void pollLines(Storage &str, std::string const &filename, std::mutex &mut);
};

inline std::size_t Consumer::getLines() const
{
    return d_lines;
}

#endif