#ifndef INCLUDED_NAMESPACES_H
#define INCLUDED_NAMESPACES_H

namespace First
{
    enum Enum
    {

    };
    void fun(First::Enum symbol);
}

namespace Second
{
    void fun(First::Enum symbol);
}

#endif