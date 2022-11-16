#ifndef INCLUDED_NUMBERS_H
#define INCLUDED_NUMBERS_H
#include <iosfwd>
#include <string>

class Numbers
{
    std::size_t d_size;
    int *d_nums;

public:
    explicit Numbers(std::size_t size);
    Numbers(std::size_t size, int value);
    Numbers(std::size_t size, int *values);
    Numbers(std::initializer_list<int> iniList);

    Numbers(Numbers const &other);
    Numbers(Numbers &&tmp);
    ~Numbers();

    void swap(Numbers &tmp);
    Numbers &operator=(Numbers const &other);
    Numbers &operator=(Numbers &&tmp);
    int &operator[](std::size_t idx);
    int const &operator[](std::size_t idx) const;
    int const getSize() const;

private:
    friend std::ostream &operator<<(std::ostream &out, Numbers const &numbers);
    int &element(std::size_t idx) const;
};

inline int const Numbers::getSize() const
{
    return d_size;
}

inline Numbers::~Numbers()
{
    delete[] d_nums;
}

inline int &Numbers::operator[](std::size_t idx)
{
    return element(idx);
}

inline int const &Numbers::operator[](std::size_t idx) const
{
    return element(idx);
}

inline int &Numbers::element(std::size_t idx) const
{
    return d_nums[idx];
}
inline bool operator==(Numbers const &lhs, Numbers const &rhs)
{
    if (lhs.getSize() != rhs.getSize())
        return false;

    for (int i = 0; i != lhs.getSize(); ++i)
    {
        if (lhs[i] != rhs[i])
            return false;
    }

    return true;
}

inline bool operator!=(Numbers const &lhs, Numbers const &rhs)
{
    return !(lhs == rhs);
}
#endif