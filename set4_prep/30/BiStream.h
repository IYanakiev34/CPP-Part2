#ifndef BISTREAM_H
#define BISTREAM_H

#include "BiStreamBuffer.h"
#include <ostream>

class BiStream : private BiStreamBuffer, public std::ostream
{
public:
    BiStream(std::ostream &one, std::ostream &two);
};

#endif