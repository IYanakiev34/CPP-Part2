#include "strings.ih"

Strings &Strings::operator+=(Strings const &other) &
{
    for (std::size_t str = 0; str != other.d_size; ++str)
        this->add(other.d_str[str]);

    return *this;
}