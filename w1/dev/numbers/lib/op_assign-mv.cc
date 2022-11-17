#include "../inc/numbers.ih"

Numbers &Numbers::operator=(Numbers &&tmp)
{
    // Guard if we are asigning to self
    if (*this != tmp)
    {
        swap(tmp);
    }
    return *this;
}