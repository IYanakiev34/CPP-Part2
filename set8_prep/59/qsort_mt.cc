#include <main.ih>

void qsort_mt(int *beg, int *end)
{
    if (end - beg <= 1)
        return;

    int lhs = *beg;
    int *mid = std::partition(beg + 1, end,
                              [&](int arg)
                              {
                                  return arg < lhs;
                              });

    std::swap(*beg, *(mid - 1));

    // use async to sort the two subarrays in separate threads
    auto left_sort = std::async(qsort_mt, beg, mid);
    auto right_sort = std::async(qsort_mt, mid, end);

    // wait for the two async calls to finish
    left_sort.wait();
    right_sort.wait();
}