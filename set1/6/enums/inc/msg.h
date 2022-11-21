#ifndef INCLUDED_MSG_H
#define INCLUDED_MSG_H

enum class Msg
{
    NONE = 0,
    DEBUG = 1 << 0,
    INFO = 1 << 1,
    NOTICE = 1 << 2,
    WARNING = 1 << 3,
    ERR = 1 << 4,
    CRIT = 1 << 5,
    ALERT = 1 << 6,
    EMERG = 1 << 7,
    ALL = (1 << 8) - 1
};

void show(Msg msg);

inline Msg operator|(Msg lhs, Msg rhs)
{
    return static_cast<Msg>(static_cast<int>(lhs) | static_cast<int>(rhs));
}

inline Msg operator&(Msg lhs, Msg rhs)
{
    return static_cast<Msg>(static_cast<int>(lhs) & static_cast<int>(rhs));
}

inline Msg operator^(Msg lhs, Msg rhs)
{
    return static_cast<Msg>(static_cast<int>(lhs) ^ static_cast<int>(rhs));
}

inline Msg operator~(Msg msg)
{
    return static_cast<Msg>(~static_cast<int>(msg));
}

inline bool operator!(Msg a)
{
    return static_cast<int>(a) == 0 ? true : false;
}

inline bool operator!=(Msg lhs, Msg rhs)
{
    return static_cast<int>(lhs) != static_cast<int>(rhs);
}

inline bool operator==(Msg lhs, Msg rhs)
{
    return lhs != rhs;
}

#endif