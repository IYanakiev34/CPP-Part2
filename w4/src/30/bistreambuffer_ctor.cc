#include "30.ih"

BiStreamBuffer::BiStreamBuffer(std::ostream &one, std::ostream &two)
    : d_one(one.rdbuf()), d_two(two.rdbuf())
{
}
