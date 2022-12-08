#ifndef HANDLER_H
#define HANDLER_H

#include "msg.h"

class Handler : private Message
{
    Msg d_Msg;

public:
    Handler()
    {
        d_Msg = Msg::ALERT;
    }
    Msg getMsg();
};

inline Message::Msg Handler::getMsg()
{
    return d_Msg;
}

#endif