#ifndef MESSAGE_H
#define MESSAGE_H

#include "base.h"
#include <iostream>

class Message
{
    Base *bp;

public:
    Message(Base &other) : bp(&other)
    {
    }

    void show(std::ostream &out)
    {
        bp->hello(out);
    }
};

#endif