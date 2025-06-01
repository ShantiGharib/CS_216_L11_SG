#include "Ceffyl.h"
#include <iomanip>
#include <fstream>
#include <sstream>

Ceffyl::Ceffyl() {
    type = CreatureTypes::CEFFYL;
}

Ceffyl::Ceffyl(const Ceffyl& source) : Creature(source) {}

Ceffyl::~Ceffyl() {}

int Ceffyl::GetDamage() const {
    static constexpr const int PERCENT_CHANCE{15}, EXTRA_FLAT_DMG{25};
    return Creature::GetDamage() + ((rand() % 100) < PERCENT_CHANCE ? EXTRA_FLAT_DMG : 0);
}
std::string Ceffyl::ToString() const {
    std::ostringstream result;

    result << Creature::ToString() << std::left << std::setw(20) << "Ceffyl" << " | " << std::right;

    return result.str();
}