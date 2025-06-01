#include "Nuggle.h"
#include "Enumeration Classes.h"
#include <iomanip>
#include <fstream>
#include <sstream>

Nuggle::Nuggle() {
    type = CreatureTypes::NUGGLE;
}
Nuggle::Nuggle(const Nuggle& source) : Creature(source) {}
Nuggle::~Nuggle() {}

int Nuggle::GetDamage() const {
    static constexpr const int PERCENT_CHANCE{25}, EXTRA_MULTIPLIER{1};
    return Creature::GetDamage() * (1 + ((rand() % 100) < PERCENT_CHANCE ? EXTRA_MULTIPLIER : 0));
}
std::string Nuggle::ToString() const {
    std::ostringstream result;

    result << Creature::ToString() << std::left << std::setw(20) << "Nuggle" << " | " << std::right;

    return result.str();
}