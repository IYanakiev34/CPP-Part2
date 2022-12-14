#ifndef BISTREAMBUFFER_H
#define BISTREAMBUFFER_H

#include <streambuf>

#include <ostream>

// Derive a class from streambuf
class BiStreamBuffer : public std::streambuf
{
    std::streambuf *d_one;
    std::streambuf *d_two;

public:
    BiStreamBuffer(std::ostream &one, std::ostream &two);

protected:
    int_type overflow(int_type ch) override;
};
#endif