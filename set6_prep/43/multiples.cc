#include "main.ih"

size_t multiples(std::vector<size_t> const &data)
{
    std::vector<size_t> tmp(data);
    size_t res = 0;

    std::for_each(tmp.begin(), tmp.end(),
                  [&](auto a) mutable
                  {
                      int count = std::count(tmp.begin(), tmp.end(), a);
                      if (count > 1)
                          res += count - 1;
                      tmp.erase(std::remove(tmp.begin(), tmp.end(), a), tmp.end());
                  });
    return res;
}