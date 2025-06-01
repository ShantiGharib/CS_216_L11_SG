#include "Bahamut.h"
#include <iomanip>
#include <fstream>
#include <sstream>

Bahamut::Bahamut() {
    type = CreatureTypes::BAHAMUT;
}
Bahamut::Bahamut(const Bahamut& source) : Creature(source) {}
Bahamut::~Bahamut() {}

int Bahamut::GetDamage() const {
    static constexpr const int TOTAL_ATKS{2};
    return TOTAL_ATKS * Creature::GetDamage();
}
std::string Bahamut::ToString() const {
    std::ostringstream result;

    result << Creature::ToString() << std::left << std::setw(20) << "Bahamut" << " | " << std::right;

    return result.str();
}