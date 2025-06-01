#include "Army.h"
#include "GlobalFunctions.h"
#include <iomanip>
#include <fstream>
#include <sstream>

Army::Army() {}


Army::Army(const Army& source) {
    operator=(source);
}


void Army::operator=(const Army& source) {
    if (this != &source) {
        name = source.name;
        maxSize = source.maxSize;

        for (int i = 0; i < maxSize; ++i) {
            //copy operator's purpose is to duplicate creatures
            *pCreatures[i] = *source.pCreatures[i];
        }
    }
}


Army::~Army() {
    name = "*";
    maxSize = usedSize = 0;
    DeallocateMemory();
}

void Army::SetArmyName(const std::string& newName) {
    name = newName;
}
bool Army::AddElement(Creature*& creature) {

    bool state = false;

    if (usedSize >= maxSize) {
        std::cerr << "Current Army at max capacity\n\n";
    }

    else if (creature != nullptr) {

        Creature::DeallocateMemory(pCreatures[usedSize]);

        pCreatures[usedSize] = creature;
        ++usedSize;

        state = true;
    }

    return state;
}


bool Army::OverwriteElement(Creature*& newCreature, const int index) {

    bool state = false;

    if (index < 0 || index >= usedSize) {
        std::cerr << "Out of Bounds memory access not permitted\n\n";
    }
    else if (newCreature != nullptr) {

        Creature::DeallocateMemory(pCreatures[index]);

        pCreatures[index] = newCreature;
        state = true;
    }
    return state;
}

bool Army::ReceiveDamage(int damage, int index) {
    return (*pCreatures[index]).ReceiveDamage(damage);
}

void Army::SortCreaturesByField(const int field) {

    bool sortStatus{false};

    while (!sortStatus) {

        sortStatus = true;

        for (int i = 1; i < usedSize; ++i) {

            bool isInversion{false};

            Creature* pPrev = pCreatures[i - 1], * pCurr = pCreatures[i];

            switch (field) {

            case static_cast<int>(CreatureFields::NAME): {

                isInversion = pPrev->GetName() > pCurr->GetName();
                break;
            }

            case static_cast<int>(CreatureFields::CURRENT_HEALTH): {

                isInversion = pPrev->GetCurrentHealth() > pCurr->GetCurrentHealth();
                break;
            }

            case static_cast<int>(CreatureFields::MAX_HEALTH): {

                isInversion = pPrev->GetMaxHealth() > pCurr->GetMaxHealth();
                break;
            }

            case static_cast<int>(CreatureFields::STRENGTH): {

                isInversion = pPrev->GetStrength() > pCurr->GetStrength();
                break;
            }

            case static_cast<int>(CreatureFields::TYPE): {

                isInversion = pPrev->GetType() > pCurr->GetType();
                break;
            }

            }

            if (isInversion) {

                sortStatus = false;

                Creature* pTemp{pCreatures[i]};

                pCreatures[i] = pCreatures[i - 1];
                pCreatures[i - 1] = pTemp;
            }

        }

    }
}


void Army::HealCreature(int index) {
    (*pCreatures[index]).HealCreature();
}


void Army::PrintNameTypeSearchQueryResults() const {

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\nEnter search query:\n\n";

    std::string searchQuery;
    std::getline(std::cin, searchQuery);

    NormalizeString(searchQuery);

    std::string result{SearchByNameHelper(searchQuery)};


    if (result.empty()) {
        std::cout << "No matching records found";
    }
    else {
        std::cout << "\nEntries Found:\n\n" << Creature::PrintHeading() << "\n" << result;
    }

    std::cout << "\n\n";

}


std::string Army::ToString() const {

    std::ostringstream result;

    result << "Army " << name << ":" << Creature::PrintHeading();

    for (int i = 0; i < usedSize; ++i) {
        result << (*pCreatures[i]).ToString() << "\n";
    }

    return result.str();
}


std::string Army::SearchByNameHelper(std::string& searchQuery) const {

    std::ostringstream result;

    for (int i = 0; i < usedSize; ++i) {

        std::string name{(*pCreatures[i]).GetName()};

        if (name.find(searchQuery) != std::string::npos) {
            result << (*pCreatures[i]).ToString() << "\n";
        }

    }

    return result.str();
}

void Army::GetFilteredHealthRangeFromUser(int& minHealth, int& maxHealth) {

    do {
        std::cout << "Please enter minimum health\n\t";
        std::cin >> minHealth;
    } while (minHealth < 0);

    do {
        std::cout << "Please enter maximum health{must be greater than minimum health}\n\t";
        std::cin >> maxHealth;
    } while (maxHealth < minHealth);

}
std::string Army::FilterView(const int& minHealth, const int& maxHealth) {

    std::ostringstream result;

    for (int i = 0; i < usedSize; ++i) {
        const int creatureCurrHealth = (*pCreatures[i]).GetCurrentHealth();
        if (creatureCurrHealth >= minHealth && creatureCurrHealth <= maxHealth) {
            result << (*pCreatures[i]).ToString() << "\n";
        }
    }

    result << "\n\n";

    return "Army " + name + ":" + (result.str().empty() ? " Creatures empty" : Creature::PrintHeading()) + result.str();
}


void Army::GetSortFieldFromUser(int& sortField) {

    int option{0};
    static constexpr const int ESCAPE{static_cast<int>(CreatureFields::SIZE)};
    while (option < static_cast<int>(CreatureFields::NAME) || option > static_cast<int>(CreatureFields::SIZE)) {

        DisplaySortMenu();

        std::cin >> option;

        switch (option) {

        case static_cast<int>(CreatureFields::NAME):
        case static_cast<int>(CreatureFields::CURRENT_HEALTH):
        case static_cast<int>(CreatureFields::MAX_HEALTH):
        case static_cast<int>(CreatureFields::STRENGTH):
        case static_cast<int>(CreatureFields::TYPE): {

            sortField = option;
            break;
        }

        case ESCAPE: {
            std::cout << "Returning To Outer Menu\n";
            break;
        }

        default: {

            HandleInvalidOption();
            break;
        }

        }
    }
}


MemoryAllocationTags Army::BuildArmy(const int forcedSize) {

    int armySize{forcedSize};
    if (armySize <= 0) {
        std::cout << "\n\nPlease enter army size:\n\t";
        std::cin >> armySize;

        while (armySize <= 0) {

            HandleInvalidOption();

            std::cout << "\n\nPlease enter army size(must be greater than zero):\n\t";
            std::cin >> armySize;
        }
    }

    MemoryAllocationTags ALLOCATION_ATTEMPT_STATE{AllocateMemory(armySize)};

    if (ALLOCATION_ATTEMPT_STATE == MemoryAllocationTags::SUCCESS) {

        static const std::string baseName{"Creature_"};

        static const int minStrengthAndHealth{120},
            maxStrengthAndHealth{250},
            minMaxRange{maxStrengthAndHealth - minStrengthAndHealth + 1};

        for (int i = 1; i <= armySize && ALLOCATION_ATTEMPT_STATE != MemoryAllocationTags::FAILURE; ++i) {

            const int STRENGTH = minStrengthAndHealth + (rand() % minMaxRange),
                HEALTH = minStrengthAndHealth + (rand() % minMaxRange);

            const int CREATURE_IDX = rand() % static_cast<int>(CreatureTypes::DEFAULT);
            Creature* randomCreature{nullptr};
            Creature::AllocateMemory(randomCreature, CREATURE_IDX);
            if (randomCreature != nullptr) {
                randomCreature->SetCreature(baseName + (i < 10 ? "0" : "") + std::to_string(i), STRENGTH, HEALTH);
                AddElement(randomCreature);
            }
            else {
                ALLOCATION_ATTEMPT_STATE = MemoryAllocationTags::FAILURE;
            }
        }
    }

    else if (ALLOCATION_ATTEMPT_STATE == MemoryAllocationTags::NEITHER) {

        enum { YES = 1, NO };
        int option{0};

        while (option != YES && option != NO) {

            if (forcedSize > 0) {
                option = YES;
            }
            else {
                std::cout << "An army has already been built. Do you wish to change the size of the army?\n1. Yes\n2. No\n\n";
                std::cin >> option;
            }

            switch (option) {

            case YES: {

                if (DeallocateMemory() == MemoryAllocationTags::SUCCESS) {
                    ALLOCATION_ATTEMPT_STATE = BuildArmy(armySize);
                }

                break;
            }
            case NO: {

                std::cout << "Returning to original menu...\n";
                break;
            }
            default: {

                HandleInvalidOption();
                break;
            }
            }
        }
    }

    if (ALLOCATION_ATTEMPT_STATE == MemoryAllocationTags::FAILURE) {
        DeallocateMemory();
        std::cerr << "Army creation unsuccessful. Try again to build the army\n\n";
    }

    return ALLOCATION_ATTEMPT_STATE;
}


MemoryAllocationTags Army::AllocateMemory(const int SIZE) {

    MemoryAllocationTags state{MemoryAllocationTags::NEITHER};
    if (pCreatures == nullptr) {

        try {
            pCreatures = new Creature * [SIZE] {};
            usedSize = 0;
            maxSize = SIZE;
            state = MemoryAllocationTags::SUCCESS;
        }

        catch (std::bad_alloc) {
            std::cerr << "Memory could not be allocated\n";
            state = MemoryAllocationTags::FAILURE;
            DeallocateMemory();
        }
    }

    return state;
}


MemoryAllocationTags Army::DeallocateMemory() {

    MemoryAllocationTags state = MemoryAllocationTags::NEITHER;
    if (pCreatures != nullptr) {

        for (int i = 0; i < usedSize; ++i) {

            if (pCreatures[i] != nullptr) {
                delete pCreatures[i];
                pCreatures[i] = nullptr;
            }
        }
        delete[] pCreatures;
        pCreatures = nullptr;
        maxSize = usedSize = 0;
        state = MemoryAllocationTags::SUCCESS;
    }

    return state;
}

void Army::DisplaySortMenu() {

    std::cout << "\n\nSort Options:"

        "\n\t1. Name"

        "\n\t2. Current Health"

        "\n\t3. Max Health"

        "\n\t4. Strength"

        "\n\t5. Type"

        "\n\t6. None: Go back to outer menu\n\n";
}