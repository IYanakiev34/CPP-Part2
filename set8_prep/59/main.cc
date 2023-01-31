#include "main.ih"

int main(int argc, char **argv)
{
    // 59 + function qsort_mt
    size_t const iaSize{100};
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