#ifndef ENUM_CLASSES_H
#define ENUM_CLASSES_H

enum class CreatureFields {

    NAME = 1,
    CURRENT_HEALTH,
    MAX_HEALTH,
    STRENGTH,
    TYPE,

    SIZE
};


enum class CreatureTypes {

    CEFFYL,
    BAHAMUT,
    CYBERBAHAMUT,
    NUGGLE,

    DEFAULT
};



enum class MemoryAllocationTags {

    SUCCESS = 1,
    FAILURE,
    NEITHER
};


enum class MainMenuOptions {

    PLAY_GAME = 1,
    SORT_BY_FIELD,
    FILTER,
    QUIT
};



#endif
