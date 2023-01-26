#include "consThr.ih"

void ConsThread::start()
{
    d_thr = std::thread{&ConsThread::poll, std::ref(*this), this};
}