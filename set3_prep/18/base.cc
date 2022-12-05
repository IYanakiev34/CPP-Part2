#include "ex18.ih"

Base::Base()
{
    std::cout << "Base constructor\n";
}

Base::Base(Base const &other)
{
    std::cout << "Base copy constructor\n";
}

Base::Base(Base &&tmp)
{
    std::cout << "Base move constructor\n";
}

Base::~Base()
{
    std::cout << "Base destructor\n";
}