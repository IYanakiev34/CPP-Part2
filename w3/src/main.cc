#include <iostream>

class Base
{
    int d_value;

public:
    Base()
    {
        std::cout << "Base cons called default\n";
        d_value = -1;
        d_prot = -2;
    };
    Base(int value) : d_value(value), d_prot(value + 1) { std::cout << "Base cons called with value param\n"; };
    ~Base() { std::cout << "Base destructor called\n"; }

    void pub()
    {
        std::cout << "Public pub called (BASE)\n";
    }

protected:
    int d_prot;

    void gun()
    {
        std::cout << "Protected gun called (BASE)\n";
    }

private:
    void fun()
    {
        std::cout << "Private void fun called (BASE)\n";
    }
};

class Derived : private Base
{
    int d_derivedValue;

public:
    Derived() { std::cout << "Derived cons called default\n"; };
    Derived(int d) : d_derivedValue(d) { std::cout << "Derived called with one value\n"; };
    ~Derived() { std::cout << "Derived dest called\n"; };

    void bun()
    {
        std::cout << "Calling fun from derived (DERIVED)\n";
        std::cout << "Lets see what we can do:... (DERIVED)\n\n";
        this->gun();
        this->pub();
        std::cout << "\nPrinting values (DERIVED)\n";
        std::cout << "Derived value: " << this->d_derivedValue << " (DERIVED)\n";
        std::cout << "Protected value from base: " << this->d_prot << " (DERIVED)\n";
    }

protected:
    void prot_derived()
    {
        std::cout << "Calling prot_derived (DERIVED)\n";
    }
};

int main(int argc, char **argv)
{
    Derived d{10};
    d.bun();

    return 0;
}