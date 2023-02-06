#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <queue>
#include <string>
#include <mutex>

class BlockingQueue
{
    std::queue<std::string> d_queue;
    std::mutex d_mut;
    bool b_finished;

public:
    BlockingQueue();
    void push(std::string const &item);
    void pop();
    std::string &front();
    bool empty();

    bool getFinished() const;
    void setFinished(bool finished);
};

inline bool BlockingQueue::getFinished() const
{
    return b_finished;
}

inline void BlockingQueue::setFinished(bool finished)
{
    b_finished = finished;
}

#endif