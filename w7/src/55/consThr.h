#ifndef CONSTHR_H
#define CONSTHR_H

#include <string>
#include <thread>
#include <fstream>

class Storage;

class ConsThread
{
    std::thread d_thr;
    Storage *d_str;
    std::size_t d_lines;
    std::string d_filename;
    std::ofstream d_out;

public:
    ConsThread(Storage &str, std::string const &filename);
    ConsThread(ConsThread &&tmp);
    ~ConsThread();

    void join();
    void start();
    std::size_t getLines();

private:
    void poll(ConsThread *thr);
};

inline void ConsThread::join()
{
    d_thr.join();
}

inline std::size_t ConsThread::getLines()
{
    return d_lines;
}

#endif