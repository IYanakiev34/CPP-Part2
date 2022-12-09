//
// Created by Alex Swaters on 12/9/2022.
//

#include "Message.h"

Message::Message(Base &base)
{
    basePtr = &base;
}

void Message::show(std::ostream &out) const
{
    basePtr->hello(out);
}