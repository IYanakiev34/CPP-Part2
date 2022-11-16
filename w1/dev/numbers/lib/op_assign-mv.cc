#include "../inc/numbers.ih"

Numbers &Numbers::operator=(Numbers &&tmp)
{
    swap(tmp);
    return *this;
}