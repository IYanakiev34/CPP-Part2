#include "../inc/numbers.ih"

namespace
{
    void *cast(Numbers *other);
}

void Numbers::swap(Numbers &tmp)
{
    enum
    {
        SIZE = sizeof(Numbers)
    };

    char buffer[SIZE];
    memcpy(buffer, cast(this), SIZE);
    memcpy(cast(this), cast(&tmp), SIZE);
    memcpy(cast(&tmp), buffer, SIZE);
}
namespace
{
    void *cast(Numbers *other)
    {
        return reinterpret_cast<void *>(other);
    }
}