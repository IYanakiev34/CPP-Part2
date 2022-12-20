#ifndef INC_37_DUMMY_H
#define INC_37_DUMMY_H

#include <utility>
#include <vector>
#include <string>
#include <iostream>

class Dummy
{
    std::vector<std::string> d_strs;

public:
    explicit Dummy(std::vector<std::string> strs)
    :
        d_strs(std::move(strs))
    {}
    void add(std::string const &str);
    void printSizeCapacity() const;

    void swap(Dummy &dummy);
};

inline void Dummy::add(std::string const &str)
{
    d_strs.emplace_back(str);
}

inline void Dummy::printSizeCapacity() const
{
    std::cout << "Size: " << d_strs.size() << "\n"
              << "Capacity: " << d_strs.capacity() << "\n";
}

inline void Dummy::swap(Dummy &dummy)
{
    d_strs.swap(dummy.d_strs);
}

#endif //INC_37_DUMMY_H
