#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "msg.h"

class Processor : private Message
{
    Msg d_Msg;

public:
    Processor();
    ~Processor() = default;

    void setMsg(Msg msg);
};

inline void Processor::setMsg(Msg msg)
{
    d_Msg = msg;
}
#endif