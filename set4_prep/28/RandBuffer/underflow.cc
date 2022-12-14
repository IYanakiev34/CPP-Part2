#include "RandBuffer.ih"

int RandBuffer::underflow()
{
    // Init the buff if needed, size = maximal # chars possible given range
    if (d_buffer == nullptr)
    {
        size_t size = 0;
        size_t pow = 1;
        while (pow < abs(d_min) or pow < abs(d_min + d_range)) {
            pow *= 10;
            size++;
        }
        d_buffer = new char[size];
        setg(d_buffer, d_buffer, d_buffer + size);
    }

    // Get value, put it on the buffer
    int value = d_min + d_range * std::rand() / (RAND_MAX + 0.1);
    while (value >= d_end)
        value = d_min + d_range * std::rand() / (RAND_MAX + 0.1);
    std::string str = std::to_string(value);
    str.copy(d_buffer, str.size());
    return *gptr();
}
