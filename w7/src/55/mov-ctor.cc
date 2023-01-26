#include "consThr.ih"

ConsThread::ConsThread(ConsThread &&tmp)
    : d_thr(std::move(tmp.d_thr)),
      d_lines(tmp.d_lines),
      d_filename(std::move(tmp.d_filename)),
      d_out(std::move(tmp.d_out))
{
    tmp.d_lines = 0;
}