//
// Created by Alex Swaters on 11/28/2022.
//

#ifndef EX11_IDENTIFIED_H
#define EX11_IDENTIFIED_H

class Identified
{
    int id;
    static int nextId;

public:
    explicit Identified(int id);
    Identified(const Identified &other);
    void showId() const;
};


#endif //EX11_IDENTIFIED_H
