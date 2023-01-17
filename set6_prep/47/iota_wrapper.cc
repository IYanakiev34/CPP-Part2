#include "iota_wrapper.h"

IotaWrapper::IotaWrapper(unsigned const &start, IotaFunc const &func)
        : d_value(start),
          d_func(func)
{
}