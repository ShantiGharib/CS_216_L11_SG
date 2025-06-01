#include "Game.h"
#include "GlobalFunctions.h"
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>



Game::Game() {
    teamA.SetArmyName("A");
    teamB.SetArmyName("B");
}


Game::Game(const Game& source) {
    operator=(source);
}


void Game::operator=(const Game& source) {
    if (this != &source) {
        teamA = source.teamA;
        teamB = source.teamB;
    }
}


Game::~Game() {}


std::string Game::ActionHeading() {

    std::ostringstream result;

    static constexpr const int WIDTH{122};

    result << "| " << std::left
        << std::setw(20) << "Attacker" << " | "
        << std::setw(10) << "Damage" << " | "
        << std::setw(20) << "Army" << " |\t"
        << std::setw(20) << "Defender" << " | "
        << std::setw(10) << "Health" << " | "
        << std::setw(20) << "Army" << " |\n" << std::right
        << PrintSeparationLine(WIDTH);

    return result.str();
}


std::string Game::ActionToString(const std::string& attacker, int damage, const std::string& attackerArmyName, const std::string& defender, int remainingHealth, const std::string& defenderArmyName) const {

    std::ostringstream result;

    result << "| " << std::left
        << std::setw(20) << attacker << " | " << std::right
        << std::setw(10) << damage << " | " << std::left
        << std::setw(20) << attackerArmyName << " |\t"
        << std::setw(20) << defender << " | " << std::right
        << std::setw(10) << remainingHealth << " | " << std::left
        << std::setw(20) << defenderArmyName << " |" << std::right;

    return result.str();
}

bool Game::CustomizeArmy() {

    int userSelectedSize = GetArmySizeFromUser();

    MemoryAllocationTags state = teamA.BuildArmy(userSelectedSize);
    if (state == MemoryAllocationTags::SUCCESS) {
        state = teamB.BuildArmy(userSelectedSize);
    }

    if (state != MemoryAllocationTags::SUCCESS) {
        teamA.DeallocateMemory();
        teamB.DeallocateMemory();
    }

    return state == MemoryAllocationTags::SUCCESS;

}

void Game::GameManager() {

    if (CustomizeArmy()) {

        //positive: team A wins; neagtive: team B wins
        int netHealth{0};

        std::cout << "\n\n"
            << teamA.ToString() << "\n\n"
            << teamB.ToString() << "\n\n"
            << ActionHeading();

        for (int i = -1 + teamA.GetCurrentSize(); i >= 0; --i) {

            const Creature& creatureA = teamA.GetElement(i), & creatureB = teamB.GetElement(i);

            teamA.HealCreature(i); teamB.HealCreature(i);

            bool teamATurn = (rand() % 2 == 0);

            while (creatureA.GetCurrentHealth() > 0 && creatureB.GetCurrentHealth() > 0) {

                if (teamATurn) {

                    const int DAMAGE = creatureA.GetDamage();

                    teamB.ReceiveDamage(DAMAGE, i);

                    std::cout
                        << ActionToString(creatureA.GetName(), DAMAGE, teamA.GetName(), creatureB.GetName(), creatureB.GetCurrentHealth(), teamB.GetName())
                        << "\n";

                    teamATurn = false;
                }

                else {

                    const int DAMAGE = creatureB.GetDamage();

                    teamA.ReceiveDamage(DAMAGE, i);

                    std::cout
                        << ActionToString(creatureB.GetName(), DAMAGE, teamB.GetName(), creatureA.GetName(), creatureA.GetCurrentHealth(), teamA.GetName())
                        << "\n";

                    teamATurn = true;
                }

            }
            netHealth += (creatureA.GetCurrentHealth() - creatureB.GetCurrentHealth());
        }

        std::cout << "\n\nWinner: ";

        if (netHealth > 0) {
            std::cout << teamA.GetName();
        }

        else if (netHealth != 0) {
            std::cout << teamB.GetName();
        }

        else {
            std::cout << "Neither: Somehow it's a tie";
        }

        std::cout << "\n\n\n" << teamA.ToString() << "\n\n" << teamB.ToString() << "\n\n";
    }
    else {
        std::cerr << "Couldn't initialize the battle instance, please try again\n";
    }
}

int Game::GetArmySizeFromUser() const {

    int userSelectedSize{0};
    std::cout << "Choose an Army Size\n";
    std::cin >> userSelectedSize;
    while (userSelectedSize <= 0 || std::cin.fail()) {
        HandleInvalidOption();
        std::cout << "Choose an Army Size(must be a positive integer)\n";
        std::cin >> userSelectedSize;
    }
    return userSelectedSize;
}

void Game::SortArmies() {

    int sortField{0};
    Army::GetSortFieldFromUser(sortField);
    if (static_cast<int>(CreatureFields::NAME) <= sortField && sortField < static_cast<int>(CreatureFields::SIZE)) {
        teamA.SortCreaturesByField(sortField);
        teamB.SortCreaturesByField(sortField);
        std::cout << "\n\n\n"
            << teamA.ToString() << "\n\n"
            << teamB.ToString() << "\n\n";
    }
}

void Game::FilterViewOfArmies() {
    int minHealth{0}, maxHealth{0};
    Army::GetFilteredHealthRangeFromUser(minHealth, maxHealth);

    std::cout << "\n\n\n"
        << teamA.FilterView(minHealth, maxHealth) << "\n\n"
        << teamB.FilterView(minHealth, maxHealth) << "\n\n";
}