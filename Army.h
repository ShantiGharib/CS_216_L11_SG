#ifndef ARMY_H
#define ARMY_H
#include "Creatures.h"

class Army {
private:
    Creature* *pCreatures{nullptr};

    int usedSize{0}, maxSize{0};
    std::string name{"*"};

    std::string SearchByNameHelper(std::string& searchQuery) const;

public:
    Army();
    Army(const Army& source);
    void operator=(const Army& source);
    ~Army();

    inline int GetCurrentSize() const;
    inline int GetCapacity() const;
    inline const std::string& GetName() const;
    inline const Creature& GetElement(const int index) const;
    void SetArmyName(const std::string& newName);
    bool AddElement(Creature*& creature);
    bool OverwriteElement(Creature*& creature, const int index);
    bool ReceiveDamage(int damage, int index);
    void HealCreature(int index);
    MemoryAllocationTags BuildArmy(const int forcedSize = 0);
    MemoryAllocationTags AllocateMemory(const int SIZE);
    MemoryAllocationTags DeallocateMemory();
    void SortCreaturesByField(const int field);
    std::string FilterView(const int& minHealth, const int& maxHealth);
    void PrintNameTypeSearchQueryResults() const;
    std::string ToString() const;
    static void GetSortFieldFromUser(int& sortField);
    static void GetFilteredHealthRangeFromUser(int& minHealth, int& maxHealth);
    static void DisplaySortMenu();
};

inline int Army::GetCurrentSize() const {
    return usedSize;
}
inline int Army::GetCapacity() const {
    return maxSize;
}
inline const std::string& Army::GetName() const {
    return name;
}
inline const Creature& Army::GetElement(const int index) const {
    return *pCreatures[index];
}



#endif