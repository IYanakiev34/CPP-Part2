#include "30.ih"

BiStream::BiStream(std::ostream &one, std::ostream &two)
    : BiStreamBuffer(one, two),
      std::ostream(this)
{
}