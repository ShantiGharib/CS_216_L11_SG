#ifndef GAME_H
#define GAME_H
#include "Army.h"

class Game {

private:
    Army teamA, teamB;

    bool CustomizeArmy();
    int GetArmySizeFromUser() const;
    static std::string ActionHeading();
public:

    Game();
    Game(const Game& source);

    void operator=(const Game& source);
    ~Game();

    void GameManager();
    void SortArmies();
    void FilterViewOfArmies();
    std::string ActionToString(const std::string& attacker, int damage, const std::string& attackerArmyName, const std::string& defender, int remainingHealth, const std::string& defenderArmyName) const;
};

#endif