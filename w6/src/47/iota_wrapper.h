#ifndef IOTA_WRAPPER_H
#define IOTA_WRAPPER_H

#include <functional>

class IotaWrapper
{
    using IotaFunc = std::function<unsigned(unsigned const &n)>;
    unsigned d_Value;
    IotaFunc d_Func;

public:
    IotaWrapper() = delete;
    IotaWrapper(unsigned const &start, IotaFunc const &func);

    operator unsigned();
    IotaWrapper &operator++();
};

#endif