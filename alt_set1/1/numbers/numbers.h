#ifndef INCLUDED_NUMBERS_H
#define INCLUDED_NUMBERS_H
#include <iosfwd>
#include <initializer_list>

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

    // Used in exercise 2 provided here for convinience and to avoid duplicating header file
    Numbers &operator+=(Numbers const &other) &;
    Numbers operator+=(Numbers const &tmp) &&;
    Numbers &operator-=(Numbers const &other) &;
    Numbers operator-=(Numbers const &tmp) &&;
    Numbers &operator*=(int rhs) &;
    Numbers operator*=(int rhs) &&;
    Numbers &operator/=(int rhs) &;
    Numbers operator/=(int rhs) &&;
    // Headers ex 2

    int &operator[](std::size_t idx);
    int const &operator[](std::size_t idx) const;

    int size() const;

private:
    friend std::ostream &operator<<(std::ostream &out, Numbers const &numbers);

    // Headers exe 2
    friend Numbers operator+(Numbers const &lhs, Numbers const &rhs);
    friend Numbers operator+(Numbers &&lhs, Numbers const &rhs);
    friend Numbers operator-(Numbers const &lhs, Numbers const &rhs);
    friend Numbers operator-(Numbers &&tmp, Numbers const &rhs);
    friend Numbers operator*(Numbers const &lhs, int rhs);
    friend Numbers operator*(Numbers &&tmp, int rhs);
    friend Numbers operator/(Numbers const &lhs, int rhs);
    friend Numbers operator/(Numbers &&tmp, int rhs);
    // Headers ex2

    int &element(std::size_t idx) const;

    // Headers ex2
    void add(Numbers const &other);
    void subtract(Numbers const &other);
    void mult(int rhs);
    void div(int rhs);
    // Headers ex2
};

bool operator==(Numbers const &lhs, Numbers const &rhs);

inline int Numbers::size() const
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

inline bool operator!=(Numbers const &lhs, Numbers const &rhs)
{
    return !(lhs == rhs);
}
#endif
