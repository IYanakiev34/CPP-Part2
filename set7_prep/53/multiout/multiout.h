#ifndef MULTIOUT_H
#define MULTIOUT_H

#include <string>

class MultiOut
{
    size_t d_numThreads;
public:
    MultiOut(const char *num_threads);
    void run();
};

inline MultiOut::MultiOut(char const *num_threads)
    : d_numThreads(std::stoul(num_threads))
{
}

#endif // MULTIOUT_H