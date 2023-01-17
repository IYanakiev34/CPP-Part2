#include "Vstring.ih"

Vstring::Vstring(std::istream &in)
{
    copy(std::istream_iterator<std::string>(in),
         std::istream_iterator<std::string>(),
         back_inserter(*this));
}