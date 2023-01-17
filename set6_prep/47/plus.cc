#include "iota_wrapper.h"

IotaWrapper &IotaWrapper::operator++()
{
    d_value = d_func(d_value);
    return *this;
}