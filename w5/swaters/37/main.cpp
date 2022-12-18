#include "main.ih"

int main()
{
    Dummy dummy{uniqueFileWords("../test.txt")};
    dummy.printSizeCapacity();
    dummy.add("hello");
    dummy.printSizeCapacity();
    Dummy{dummy}.swap(dummy);
    dummy.printSizeCapacity();
}
