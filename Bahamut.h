#ifndef BAHAMUT_H
#define BAHAMUT_H
#include "Creatures.h"

class Bahamut : public Creature {
public:
    Bahamut();
    Bahamut(const Bahamut& source);

    virtual ~Bahamut();

    virtual int GetDamage() const override;
    virtual std::string ToString() const override;
};

#endif