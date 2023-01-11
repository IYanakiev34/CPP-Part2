#include "smart_str.ih"

SmartStrings::SmartStrings(std::size_t size, std::string const &word) : d_str(size, std::make_shared<std::string>(word))
{
}