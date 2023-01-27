#include "consumer.ih"

Consumer::Consumer(Storage &ref, std::string const &filename, std::mutex &mut)
    : d_mut(&mut),
      d_str(&ref),
      d_filename(filename),
      d_lines(0)
{
}