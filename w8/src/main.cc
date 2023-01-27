#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <future>
#include <algorithm>
#include <functional>

#include <iterator>
#include <thread>

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

std::string threadFun()
{
    std::cerr << "entry\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cerr << "first cerr\n";

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cerr << "second cerr\n";

    return "end the program";
}

int main(int argc, char **argv)
{

    /*58
    double lhs[4][5];
    double rhs[6][5];

    // fill lhs with 2s
    std::for_each(lhs, lhs + 4, [](auto &v)
                  { std::fill(v, v + 5, 2); });

    // fill rhs with 4s
    std::for_each(rhs, rhs + 6, [](auto &v)
                  { std::fill(v, v + 5, 4); });

    std::future<double> fut[4][6];

    for (std::size_t row = 0; row < 4; ++row)
    {
        for (std::size_t col = 0; col < 6; ++col)
        {
            std::packaged_task<double()> task{[&]()
                                              { return std::inner_product(&lhs[row][0], &lhs[row][5], &rhs[col][0], 0.0); }};
            fut[row][col] = task.get_future();
            std::thread(std::move(task)).detach();
        }
    }

    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 6; ++col)
            std::cout << fut[row][col].get() << " ";
        std::cout << "\n";
    }
    */

    // NOTE to ALEX
    // The method should be correct however due to the nature of the raw arrays
    // there may be problem with contigious memory. The last two future results
    // seem to be off (uninitialized memory)

    // option A I am stupid and there is problem with the ranges
    // option B wrong method but i doubt it

    // 59 + function qsort_mt
    /*
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
    */

    // 60
    // Start the threadFun in a separate thread
    std::future<std::string> result = std::async(std::launch::async, threadFun);

    size_t count = 0;
    while (true)
    {
        // do the main-task
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cerr << "inspecting: " << ++count << '\n';

        // inspect whether the thread indicates to end the program
        if (result.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
        {
            std::cerr << "done\n";
            break;
        }
    }
    return 0;
}
