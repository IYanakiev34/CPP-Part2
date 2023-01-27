#include "consumer.ih"

void Consumer::startThread()
{
    d_thr = std::thread(&Consumer::pollLines, std::ref(*this), std::ref(*d_str), std::ref(d_filename), std::ref(*d_mut));
}