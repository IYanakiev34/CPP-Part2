#include <utility>
#include <iostream>
#include "library.h"

/*
 * I know I should split functions into their own files, but I'm keeping them together
 * for development purposes. If we were to submit this I'd see to it then.
 */

// Basic constructors
Numbers::Numbers(size_t size)
: d_size(size)
, d_nums(new int[size])
{
}

Numbers::Numbers(size_t size, int value)
: d_size(size)
, d_nums(new int[size])
{
    for (size_t i = 0; i != size; ++i)
        d_nums[i] = value;
}

Numbers::Numbers(size_t size, int const *values)
: d_size(size)
, d_nums(new int[size])
{
    for (size_t i = 0; i != size; ++i)
        d_nums[i] = values[i];
}

Numbers::Numbers(std::initializer_list<int> iniList)
: d_size(iniList.size())
, d_nums(new int[d_size])
{
    size_t i = 0;
    for (int it : iniList)
        d_nums[i++] = it;
}

// Move and copy constructors
Numbers::Numbers(Numbers const &other)
: d_size(other.d_size)
, d_nums(new int[d_size])
{
    for (size_t i = 0; i != d_size; ++i)
        d_nums[i] = other.d_nums[i];
}

Numbers::Numbers(Numbers &&tmp) noexcept
: d_size(tmp.d_size)
, d_nums(tmp.d_nums)
{
    tmp.d_size = 0;
    tmp.d_nums = nullptr;
}

// Fast swap according to the annotations (page 238)
void Numbers::swap(Numbers &other)
{
    char buffer[sizeof(Numbers)];
    memcpy(buffer, this, sizeof(Numbers));
    memcpy(static_cast<void *>(this), &other, sizeof(Numbers));
    memcpy(static_cast<void *>(&other), buffer,sizeof(Numbers));
}

// Move and copy assignment operators
Numbers &Numbers::operator=(Numbers const &other) {
    if (this != &other) {
        Numbers tmp{other};
        swap(tmp);
    }
    return *this;
}

Numbers &Numbers::operator=(Numbers &&tmp) noexcept {
    if (this != &tmp) {
        swap(tmp);
    }
    return *this;
}

// Lvalue compound assignment operators, copying page 328
Numbers &Numbers::operator+=(Numbers const &other) &{
    Numbers tmp{*this};
    tmp.add(other);
    swap(tmp);
    return *this;
}

Numbers &Numbers::operator-=(Numbers const &other) &{
    Numbers tmp{*this};
    tmp.subtract(other);
    swap(tmp);
    return *this;
}

Numbers &Numbers::operator*=(int rhs) &{
    Numbers tmp{*this};
    tmp.multiply(rhs);
    swap(tmp);
    return *this;
}

Numbers &Numbers::operator/=(int rhs) &{
    Numbers tmp{*this};
    tmp.divide(rhs);
    swap(tmp);
    return *this;
}

// Rvalue compound assignment operators, copying page 328
Numbers &&Numbers::operator+=(Numbers &&tmp) &&
{
    add(tmp);
    return std::move(*this);
}

Numbers &&Numbers::operator-=(Numbers &&tmp) &&
{
    subtract(tmp);
    return std::move(*this);
}

Numbers &&Numbers::operator*=(int rhs) &&
{
    multiply(rhs);
    return std::move(*this);
}

Numbers &&Numbers::operator/=(int rhs) &&
{
    divide(rhs);
    return std::move(*this);
}

// Output operator
std::ostream &operator<<(std::ostream &out, Numbers const &numbers) {
    for (size_t i = 0; i != numbers.size(); ++i)
        out << numbers[i] << ' ';
    return out << '\n';
}

// Lvalue binary operators
Numbers operator+(Numbers const &lhs, Numbers const &rhs) {
    Numbers tmp{lhs};
    tmp.add(rhs);
    return tmp;
}

Numbers operator-(Numbers const &lhs, Numbers const &rhs) {
    Numbers tmp{lhs};
    tmp.subtract(rhs);
    return tmp;
}

Numbers operator*(Numbers const &lhs, int rhs) {
    Numbers tmp{lhs};
    tmp.multiply(rhs);
    return tmp;
}

Numbers operator/(Numbers const &lhs, int rhs) {
    Numbers tmp{lhs};
    tmp.divide(rhs);
    return tmp;
}

// Rvalue binary operators
Numbers operator+(Numbers &&lhs, Numbers const &rhs) {
    lhs.add(rhs);
    return std::move(lhs);
}

Numbers operator-(Numbers &&lhs, Numbers const &rhs) {
    lhs.subtract(rhs);
    return std::move(lhs);
}

Numbers operator*(Numbers &&lhs, int rhs) {
    lhs.multiply(rhs);
    return std::move(lhs);
}

Numbers operator/(Numbers &&lhs, int rhs) {
    lhs.divide(rhs);
    return std::move(lhs);
}


// Indexing overload
void Numbers::boundary(size_t index) const {
    if (index < d_size)
        return;
    std::cerr << "Index " << index << " out of range " << d_size << std::endl;
}

int &Numbers::operatorIndex(size_t index) const
{
    boundary(index);
    return d_nums[index];
}

// Private arithmetic functions
void Numbers::add(Numbers const &other) {
    if (d_size != other.d_size) {
        std::cerr << "Cannot add numbers of different sizes" << std::endl;
        return;
    }
    for (size_t i = 0; i != d_size; ++i)
        d_nums[i] += other.d_nums[i];
}

void Numbers::subtract(Numbers const &other) {
    if (d_size != other.d_size) {
        std::cerr << "Cannot subtract numbers of different sizes" << std::endl;
        return;
    }
    for (size_t i = 0; i != d_size; ++i)
        d_nums[i] -= other.d_nums[i];
}

void Numbers::multiply(int rhs) {
    for (size_t i = 0; i != d_size; ++i)
        d_nums[i] *= rhs;
}

void Numbers::divide(int rhs) {
    for (size_t i = 0; i != d_size; ++i)
        d_nums[i] /= rhs;
}




















