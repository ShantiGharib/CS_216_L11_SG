#ifndef CEFFYL_H
#define CEFFYL_H
#include "Creatures.h"

class Ceffyl : public Creature {
public:
    Ceffyl();
    Ceffyl(const Ceffyl& source);

    ~Ceffyl();

    virtual int GetDamage() const override;
    virtual std::string ToString() const override;

};

#endif