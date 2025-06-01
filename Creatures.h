#ifndef CREATURES_H
#define CREATURES_H
#include <iostream>
#include "Enumeration Classes.h"


class Creature {
private:
    static constexpr const int HEALTH_DEFAULT{100}, STRENGTH_DEFAULT{100};

    int maxHealth{HEALTH_DEFAULT},
        strength{STRENGTH_DEFAULT},
        currentHealth{HEALTH_DEFAULT};

    std::string name{"*"};

    static Creature* AllocateNewCreature(int id);

protected:
    CreatureTypes type{CreatureTypes::DEFAULT};
public:

    Creature();

    Creature(const Creature& source);
    void operator=(const Creature& source);

    Creature(const std::string& creatureName);
    Creature(const std::string& creatureName, int creatureHealth, int creatureStrength);

    virtual ~Creature();


    inline int GetMaxHealth() const;
    inline int GetCurrentHealth() const;
    inline int GetStrength() const;
    inline const std::string& GetName() const;
    inline CreatureTypes GetType() const;
    bool ReceiveDamage(int damage);
    void HealCreature();
    virtual int GetDamage() const;

    static std::string PrintHeading();
    virtual std::string ToString() const;
    void SetCreature(const std::string& creatureName, int health, int strength);

    static MemoryAllocationTags AllocateMemory(Creature*& curr, int id = static_cast<int>(CreatureTypes::DEFAULT));
    static MemoryAllocationTags DeallocateMemory(Creature*& curr);
};


inline int Creature::GetMaxHealth() const {
    return maxHealth;
}
inline int Creature::GetCurrentHealth() const {
    return currentHealth;
}
inline int Creature::GetStrength() const {
    return strength;
}
inline const std::string& Creature::GetName() const {
    return name;
}
inline CreatureTypes Creature::GetType() const {
    return type;
}



#endif
