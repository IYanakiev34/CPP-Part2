#include "main.ih"

void testPrintNamesEnums()
{
    show(Msg::NONE);
    show(Msg::NONE | Msg::EMERG);
    show(Msg::ALERT | Msg::CRIT);
    show(Msg::ALL & (Msg::ERR | Msg::WARNING));
    show(~Msg::NOTICE);
}

int main()
{
    testPrintNamesEnums();
    return 0;
}