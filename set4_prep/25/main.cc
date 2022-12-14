#include "base.h"
#include "derived.h"
#include "message.h"

int main(int argc, char **argv) //JB: Unused params.
{

    Base bp;

    std::string name{"Hi I am Ivan"}; //JB: COCO
    Derived der(name);

    Message msg1(bp);
    Message msg2(der);

    msg1.show(std::cout);
    msg2.show(std::cout);

    return 0; //JB: SF. Zero return status is default in C++.
}
/* JB:
   It looks like you understand virtual member functions.
   Just please fix the details.
 */
