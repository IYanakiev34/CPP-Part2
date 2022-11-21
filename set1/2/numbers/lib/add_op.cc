#include "../inc/numbers.ih"

void Numbers::add(Numbers const &other)
{
    if (other.d_size != this->d_size)
    {
        std::cerr << "Cannot add objects of different sizes\n";
        return;
    }

    for (std::size_t i = 0; i != this->d_size; ++i)
        this->d_nums[i] += other.d_nums[i];
}