#ifndef MESSAGE_H
#define MESSAGE_H

#include "base.h"
#include <iostream>

class Message
{
    Base *d_bp;

public:
    explicit Message(Base &other) : d_bp(&other)
    {
    }

    void show(std::ostream &out); // inlined this
};

inline void Message::show(std::ostream &out)
{
    d_bp->hello(out);
}

#endif