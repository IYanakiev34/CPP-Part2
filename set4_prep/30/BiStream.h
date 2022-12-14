#ifndef BISTREAM_H
#define BISTREAM_H

#include "BiStreamBuffer.h"
#include <ostream>

// Definitions inside the header for brievity
class BiStream : private BiStreamBuffer, public std::ostream
{
public:
    // Constructor takes two ostream objects
    BiStream(std::ostream &one, std::ostream &two) : BiStreamBuffer(one, two),
                                                     std::ostream(this)
    { //JB: ICI
    }
};

#endif
