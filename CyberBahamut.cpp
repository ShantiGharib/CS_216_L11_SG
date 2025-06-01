#include "CyberBahamut.h"
#include <iomanip>
#include <fstream>
#include <sstream>

CyberBahamut::CyberBahamut() : Bahamut() {
    type = CreatureTypes::CYBERBAHAMUT;
}
CyberBahamut::CyberBahamut(const CyberBahamut& source) : Bahamut(source) {}
CyberBahamut::~CyberBahamut() {

}
int CyberBahamut::GetDamage() const {
    static constexpr const int PERCENT_CHANCE{10}, EXTRA_FLAT_DMG{30};
    return Bahamut::GetDamage() + ((rand() % 100) < PERCENT_CHANCE ? EXTRA_FLAT_DMG : 0);
}

std::string CyberBahamut::ToString() const {
    std::ostringstream result;

    result << Creature::ToString() << std::left << std::setw(20) << "CyberBahamut" << " | " << std::right;

    return result.str();
}