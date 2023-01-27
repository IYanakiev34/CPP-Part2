#include <iostream>
#include <numeric>
#include <future>
#include <algorithm>
#include <iterator>

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

int main(int argc, char **argv)
{

    // 59 + function qsort_mt
    std::size_t const iaSize{100};
    int ia[iaSize];

    std::iota(ia, ia + iaSize, 0);
    std::random_shuffle(ia, ia + iaSize);

    std::cout << "Before sort:\n";
    std::copy(ia, ia + iaSize, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    qsort_mt(ia, ia + iaSize);

    std::cout << "After sort:\n";
    std::copy(ia, ia + iaSize, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}