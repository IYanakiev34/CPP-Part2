#include "Semaphore.h"

Semaphore::Semaphore(std::size_t size) : d_available(size)
{
}