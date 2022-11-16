#include "../include/numbers.ih"

std::ostream &operator<<(std::ostream &out, Numbers const &numbers)
{
    for (std::size_t i = 0; i != numbers.d_size; ++i)
    {
        out << numbers.d_nums[i] << ' ';
        if (!out)
            break;
    }

    return out;
}