#include "../inc/numbers.ih"

Numbers Numbers::operator+=(Numbers const &tmp) &&
{
    this->add(tmp);
    return std::move(*this); // return a move contructed copy
}
