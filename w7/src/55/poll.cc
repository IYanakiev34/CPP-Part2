#include "consThr.ih"

void ConsThread::poll(ConsThread *thr)
{
    std::cout << "poll add: " << thr->d_str << "\n";
    std::cout << "here\n";
    while (!thr->d_str->getFinished())
    {
        std::cout << "before sleep\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "after sleep\n";
        if (!thr->d_str->empty())
        {
            thr->d_out << thr->d_str->front() << "\n";
            thr->d_str->pop();
            ++thr->d_lines;
        }
    }
}