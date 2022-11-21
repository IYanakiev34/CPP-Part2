#ifndef INCLUDED_NUMBERS_H_
#define INCLUDED_NUMBERS_H_

#include <iosfwd>
#include <initializer_list>

class Numbers
{
    size_t d_size = 0;
    int *d_nums = nullptr;

public:
    // Basic constructors
    explicit Numbers(size_t size);
    Numbers(size_t size, int value);
    Numbers(size_t size, const int *values);
    Numbers(std::initializer_list<int> iniList);

    // Move and copy constructors
    Numbers(Numbers const &other);
    Numbers(Numbers &&tmp) noexcept ;

    // Destructor
    ~Numbers();

    // Move and copy assignment operators
    void swap(Numbers &other);
    Numbers &operator=(Numbers const &other);
    Numbers &operator=(Numbers &&tmp) noexcept ;

    // Read/writable indexing operators
    int &operator[](size_t index);
    int const &operator[](size_t index) const;

    // Size
    size_t size() const;

    // Lval compound assignment operators
    Numbers &operator+=(Numbers const &other) &;
    Numbers &operator-=(Numbers const &other) &;
    Numbers &operator*=(int rhs) &;
    Numbers &operator/=(int rhs) &;

    // Rval compound assignment operators
    Numbers &&operator+=(Numbers &&tmp) &&;
    Numbers &&operator-=(Numbers &&tmp) &&;
    Numbers &&operator*=(int rhs) &&;
    Numbers &&operator/=(int rhs) &&;

private:
    // Ostream insertion operator
    friend std::ostream &operator<<(std::ostream &out, Numbers const &numbers);

    // Lval binary operators
    friend Numbers operator+(Numbers const &lhs, Numbers const &rhs);
    friend Numbers operator-(Numbers const &lhs, Numbers const &rhs);
    friend Numbers operator*(Numbers const &lhs, int rhs);
    friend Numbers operator/(Numbers const &lhs, int rhs);

    // Rval binary operators
    friend Numbers operator+(Numbers &&lhs, Numbers const &rhs);
    friend Numbers operator-(Numbers &&lhs, Numbers const &rhs);
    friend Numbers operator*(Numbers &&lhs, int rhs);
    friend Numbers operator/(Numbers &&lhs, int rhs);

    // Element
    void boundary(size_t index) const;
    int &operatorIndex(size_t index) const;

    // Arithmetic
    void add(Numbers const &other);
    void subtract(Numbers const &other);
    void multiply(int rhs);
    void divide(int rhs);
};

inline Numbers::~Numbers()
{
    delete[] d_nums;
}

inline int &Numbers::operator[](size_t index)
{
    return operatorIndex(index);
}

inline int const &Numbers::operator[](size_t index) const
{
    return operatorIndex(index);
}

inline size_t Numbers::size() const
{
    return d_size;
}




#endif