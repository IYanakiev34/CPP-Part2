#ifndef BISTREAMBUFFER_H
#define BISTREAMBUFFER_H

#include <streambuf>
#include <cstddef>

class BiStreamBuffer : public std::streambuf
{
public:
    BiStreamBuffer();
};

#endif