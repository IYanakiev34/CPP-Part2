#include "numbers.ih"

std::ostream &operator<<(std::ostream &out, Numbers const &numbers)
{
    for (std::size_t idx = 0; idx != numbers.d_size; ++idx)
    {
        out << numbers.d_nums[idx] << ' ';
        if (!out)
            break;
    }

    return out;
}