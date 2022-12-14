//JB: 0
#ifndef BISTREAMBUFFER_H
#define BISTREAMBUFFER_H

#include <ostream>

class BiStreamBuffer : public std::streambuf
{
    //JB: Data first, please, with 'd_' prefixes.
public:
    BiStreamBuffer(std::ostream &one, std::ostream &two);

protected:
    int_type overflow(int_type ch) override;

private:
    std::streambuf *one_;
    std::streambuf *two_;
};
#endif
/* JB:
   Using streambuf data members, you're interfering with the internals of two
   streams. IMO it'd be better to manipulate the streams, not their buffers
   directly.
 */
