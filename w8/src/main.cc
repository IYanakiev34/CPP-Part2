#include <iostream>

#include <numeric>
#include <vector>
#include <future>
#include <algorithm>
#include <functional>

int main(int argc, char **argv)
{
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

    // NOTE to ALEX
    // The method should be correct however due to the nature of the raw arrays
    // there may be problem with contigious memory. The last two future results
    // seem to be off (uninitialized memory)

    // option A I am stupid and there is problem with the ranges
    // option B wrong method but i doubt it
    return 0;
}
