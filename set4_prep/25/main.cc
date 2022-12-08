#include "base.h"
#include "derived.h"
#include "message.h"

int main(int argc, char **argv)
{

    Base bp;

    std::string name{"Hi I am Ivan"};
    Derived der(name);

    Message msg1(bp);
    Message msg2(der);

    msg1.show(std::cout);
    msg2.show(std::cout);

    return 0;
}