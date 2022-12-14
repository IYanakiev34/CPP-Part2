#ifndef INC_28_RANDBUFFER_H
#define INC_28_RANDBUFFER_H


#include <cstddef>
#include <streambuf>

class RandBuffer : public std::streambuf
{
    int d_min;
    int d_range;
    int d_end;
    char *d_buffer;

public:
    RandBuffer(int min, int max, size_t seed);

    int_type underflow() override;
};


#endif //INC_28_RANDBUFFER_H
