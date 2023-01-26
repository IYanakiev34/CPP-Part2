#ifndef STORAGE_H
#define STORAGE_H

#include <queue>
#include <mutex>
#include <string>

class Storage
{
    std::queue<std::string> d_queue;
    std::mutex d_mut;
    bool d_finished;

public:
    Storage();
    void push(std::string const &line);
    void pop();
    bool empty();
    std::string &front();

    bool getFinished();
    void setFinished(bool state);
};

inline bool Storage::getFinished()
{
    return d_finished;
}

inline void Storage::setFinished(bool state)
{
    d_finished = state;
}
#endif