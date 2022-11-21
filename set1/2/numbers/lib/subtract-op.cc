#include "../inc/numbers.ih"

void Numbers::subtract(Numbers const &other)
{
    if (this->d_size != other.d_size)
    {
        std::cerr << "Cannot subtract objects of different sizes\n";
        return;
    }

    for (std::size_t i = 0; i != other.d_size; ++i)
        this->d_nums[i] -= other.d_nums[i];
}