#include "strings.ih"

void Strings::swap(Strings &other)
{
    char buffer[sizeof(Strings)];
    memcpy(buffer, this,   sizeof(Strings));
    memcpy(this,   &other, sizeof(Strings));
    memcpy(static_cast<void *>(&other), buffer, sizeof(Strings));
}
