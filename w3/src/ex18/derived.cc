#include "ex18.ih"

Derived::Derived()
{
    std::cout << "Derived constructor called\n";
}

Derived::Derived(Derived const &other)
    : Base(static_cast<Base &&>(const_cast<Derived &>(other)))
{
    std::cout << "Derived copy constructor\n";
}

Derived::Derived(Derived &&tmp)
    : Base(tmp)
{
    std::cout << "Derived move constructor\n";
}

Derived::~Derived()
{
    std::cout << "Derived destructor\n";
}