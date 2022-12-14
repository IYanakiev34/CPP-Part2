#ifndef BISTREAMBUFFER_H
#define BISTREAMBUFFER_H

#include <ostream>

class BiStreamBuffer : public std::streambuf
{
public:
    BiStreamBuffer(std::ostream &one, std::ostream &two);

protected:
    int_type overflow(int_type ch) override;

private:
    std::streambuf *one_;
    std::streambuf *two_;
};

#endif