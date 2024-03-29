#include <iostream>
#include "Derived.h"
#include "Message.h"

int main()
{
    Base base;
    Derived derived{"hello from Derived"};

    Message message1{base};
    Message message2{derived};

    message1.show(std::cout);
    message2.show(std::cout);
}
