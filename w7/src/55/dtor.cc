#include "consThr.ih"

ConsThread::~ConsThread()
{
    if (d_thr.joinable())
        d_thr.join();
}