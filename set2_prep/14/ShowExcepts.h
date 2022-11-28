#ifndef EX14_SHOWEXCEPTS_H
#define EX14_SHOWEXCEPTS_H

class ShowExcepts
{
    void (*func)();
    int val;
public:
    ShowExcepts(void (*)(), int);
    void asNoexcept();
};

#endif //EX14_SHOWEXCEPTS_H
