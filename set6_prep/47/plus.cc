#include "iota_wrapper.h"

IotaWrapper &IotaWrapper::operator++()
{
    d_Value = d_Func(d_Value);
    return *this;
}