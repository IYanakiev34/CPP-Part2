//
// Created by Alex Swaters on 12/9/2022.
//

#ifndef INC_25_DERIVED_H
#define INC_25_DERIVED_H


#include "Base.h"

class Derived : public Base
{
    std::string str;
public:
    explicit Derived(std::string str);
private:
    void vHello(std::ostream& out) const override;
};


#endif //INC_25_DERIVED_H
