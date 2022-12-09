//
// Created by Alex Swaters on 12/9/2022.
//

#ifndef INC_25_BASE_H
#define INC_25_BASE_H


#include <ostream>

class Base
{
public:
    void hello(std::ostream& out) const;
private:
    virtual void vHello(std::ostream& out) const;
};

inline void Base::hello(std::ostream& out) const
{
    vHello(out);
}


#endif //INC_25_BASE_H
