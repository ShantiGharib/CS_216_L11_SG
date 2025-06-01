#ifndef NUGGLE_H
#define NUGGLE_H
#include "Creatures.h"

class Nuggle : public Creature {
private:
public:
    Nuggle();
    Nuggle(const Nuggle& source);

    ~Nuggle();

    virtual int GetDamage() const override;
    virtual std::string ToString() const override;
};

#endif