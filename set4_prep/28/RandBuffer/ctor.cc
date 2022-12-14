#include "RandBuffer.ih"

RandBuffer::RandBuffer(int min, int max, size_t seed)
        :
        d_min(min),
        d_range(max - min + 1),
        d_end(RAND_MAX - RAND_MAX % d_range), // d_end is multiple of d_range
        d_buffer(nullptr)
{
    if (max <= min)
        throw std::range_error{" min. value must be smaller than max. value"};

    srand(seed);
    setg(nullptr, nullptr, nullptr); // initially no buffer
}