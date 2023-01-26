#include "consThr.ih"

ConsThread::ConsThread(Storage &str, std::string const &filename)
    : d_str(&str),
      d_lines(0),
      d_filename(filename)
{
}