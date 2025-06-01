#include "Creatures.h"
#include "Ceffyl.h"
#include "CyberBahamut.h"
#include "Nuggle.h"
#include "GlobalFunctions.h"
#include <iomanip>
#include <fstream>
#include <sstream>


Creature::Creature() {}

Creature::Creature(const std::string& creatureName) {

    static constexpr const int RANGE{51}, MIN_VAL{50};
    SetCreature(creatureName, MIN_VAL + (rand() % RANGE), MIN_VAL + (rand() % RANGE));
}

Creature::Creature(const std::string& creatureName, int creatureStrength, int creatureHealth) {
    SetCreature(creatureName, creatureStrength, creatureHealth);
}

Creature::Creature(const Creature& source) {
    operator=(source);
}

void Creature::operator=(const Creature& source) {
    if (this != &source) {
        SetCreature(source.GetName(), source.GetMaxHealth(), source.GetStrength());
    }
}

Creature::~Creature() {
    SetCreature("*", STRENGTH_DEFAULT, HEALTH_DEFAULT);
}

int Creature::GetDamage() const {
    return 1 + (rand() % strength);
}

bool Creature::ReceiveDamage(int damage) {

    currentHealth = std::max(0, currentHealth - damage);
    return currentHealth > 0;
}

void Creature::SetCreature(const std::string& creatureName, int creatureHealth, int creatureStrength) {

    name = creatureName;
    maxHealth = currentHealth = creatureHealth;
    strength = creatureStrength;
}

std::string Creature::ToString() const {

    std::ostringstream result;

    result << "| " << std::left
        << std::setw(15) << name << " | " << std::right
        << std::setw(15) << currentHealth << " | "
        << std::setw(10) << maxHealth << " | "
        << std::setw(10) << strength << " | ";

    return result.str();
}

std::string Creature::PrintHeading() {

    std::ostringstream result;
    static constexpr const int WIDTH{86};

    result << "\n\n| " << std::left
        << std::setw(15) << "Name" << " | "
        << std::setw(15) << "Current Health" << " | "
        << std::setw(10) << "Max Health" << " | "
        << std::setw(10) << "Strength" << " | "
        << std::setw(20) << "Type" << " | " << "\n"
        << PrintSeparationLine(WIDTH) << std::right;

    return result.str();
}

Creature* Creature::AllocateNewCreature(int id) {
    //Helper function of "AllocateMemory"
    Creature* curr{nullptr};
    switch (id) {
        case static_cast<int>(CreatureTypes::CEFFYL): {
            curr = new Ceffyl();
            break;
        }
        case static_cast<int>(CreatureTypes::BAHAMUT): {
            curr = new Bahamut();
            break;
        }
        case static_cast<int>(CreatureTypes::CYBERBAHAMUT): {
            curr = new CyberBahamut();
            break;
        }
        case static_cast<int>(CreatureTypes::NUGGLE): {
            curr = new Nuggle();
            break;
        }
        default: {
            std::cerr << "Invalid Creature Type ID\n";
            break;
        }
    }
    return curr;
}

MemoryAllocationTags Creature::AllocateMemory(Creature*& curr, int id) {

    MemoryAllocationTags state{MemoryAllocationTags::NEITHER};
    if (curr == nullptr) {
        try {
            curr = AllocateNewCreature(id);
            state = MemoryAllocationTags::SUCCESS;
        }
        catch (std::bad_alloc) {
            std::cerr << "Memory could not be allocated\n";
            state = MemoryAllocationTags::FAILURE;
            DeallocateMemory(curr);
        }
    }

    return state;
}

MemoryAllocationTags Creature::DeallocateMemory(Creature*& curr) {

    MemoryAllocationTags state = MemoryAllocationTags::NEITHER;
    if (curr != nullptr) {
        delete curr;
        curr = nullptr;
        state = MemoryAllocationTags::SUCCESS;
    }

    return state;
}