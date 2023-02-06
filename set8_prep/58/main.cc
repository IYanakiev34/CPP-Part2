#include <algorithm>
#include <future>
#include <numeric>
#include <iostream>

int main()
{
    double lhs[4][5];
    double rhs[6][5];
    std::for_each(lhs, lhs + 4, [](auto &v){ std::fill(v, v + 5, 2); });
    std::for_each(rhs, rhs + 6, [](auto &v){ std::fill(v, v + 5, 4); });

    std::future<double> fut[4][6];
    for (size_t row = 0; row != 4; ++row)
    {
        for (size_t col = 0; col != 6; ++col)
        {
            std::packaged_task<double()> task([=]
            {
                return std::inner_product(
                    lhs[row], lhs[row] + 5, rhs[col], 0.0);
            });
            fut[row][col] = task.get_future();
            std::thread(std::move(task)).detach();
        }
    }

    for (size_t row = 0; row != 4; ++row)
    {
        for (size_t col = 0; col != 6; ++col)
            std::cout << fut[row][col].get() << ' ';
        std::cout << std::endl;
    }
    
}