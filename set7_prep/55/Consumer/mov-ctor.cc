#include "consumer.ih"

Consumer::Consumer(Consumer &&tmp)
    : d_thr(std::move(tmp.d_thr)),
      d_mut(tmp.d_mut),
      d_str(tmp.d_str),
      d_filename(std::move(tmp.d_filename)),
      d_lines(tmp.d_lines)
{
    tmp.d_lines = 0;
    tmp.d_str = nullptr;
    tmp.d_mut = nullptr;
}