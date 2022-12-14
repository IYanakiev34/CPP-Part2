#include "bistream.ih"

BiStreamBuffer::BiStreamBuffer(std::ostream &one, std::ostream &two)
    : one_(one.rdbuf()), two_(two.rdbuf())
{
}