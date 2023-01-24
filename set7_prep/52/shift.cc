#include "handler.ih"

void Handler::shift(std::ostream &out, std::string const &text)
{
    std::string tmp{text};

    for (std::size_t iter = 0; iter != text.size() - 1; ++iter)
    {
        out << tmp << "\n";
        std::rotate(tmp.begin(), tmp.begin() + 1, tmp.end());
    }
}