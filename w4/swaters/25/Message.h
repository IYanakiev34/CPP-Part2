//
// Created by Alex Swaters on 12/9/2022.
//

#ifndef INC_25_MESSAGE_H
#define INC_25_MESSAGE_H


#include "Base.h"

class Message
{
    Base *basePtr;
public:
    explicit Message(Base &base);
    void show(std::ostream &out) const;
};


#endif //INC_25_MESSAGE_H
