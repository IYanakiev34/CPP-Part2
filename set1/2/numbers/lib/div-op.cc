#include "../inc/numbers.ih"

void Numbers::div(int rhs)
{
    if (rhs == 0)
    {
        std::cerr << "Cannot divide by 0!\n";
        return;
    }

    for (std::size_t i = 0; i != this->d_size; ++i)
        this->d_nums[i] /= rhs;
}