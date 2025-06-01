//Shanti Gharib
//Lab 11

#include "Game.h"
#include "GlobalFunctions.h"


enum class CreatureFields;
enum class CreatureTypes;
enum class MemoryAllocationTags;
enum class MainMenuOptions;
class Creature;
class Ceffyl;
class Bahamut;
class CyberBahamut;
class Nuggle;
class Army;
class Game;


int main() {

    srand(0);

    int option{0};
    Game currentGame;

    while (option != static_cast<int>(MainMenuOptions::QUIT)) {

        DisplayMainMenu();
        std::cin >> option;

        switch (option) {

            case static_cast<int>(MainMenuOptions::PLAY_GAME): {
                currentGame.GameManager();
                break;
            }

            case static_cast<int>(MainMenuOptions::SORT_BY_FIELD): {

                currentGame.SortArmies();
                break;
            }

            case static_cast<int>(MainMenuOptions::FILTER): {

                currentGame.FilterViewOfArmies();
                break;
            }

            case static_cast<int>(MainMenuOptions::QUIT): {

                std::cout << "\nProgram now closed\n\n";
                break;
            }

            default: {

                HandleInvalidOption();
                break;
            }
        }

    }
    return EXIT_SUCCESS;
}





































































//Testcases:
//TestCase1: Game Function: Choosing Army Size of 50
//Options:
//        1. Play
//        2. Sort Creatures by Field
//        3. Filter Creatures by Health Range
//        4. Quit
//
//1
//Choose an Army Size
//50
//
//
//Army A:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_01     |             158 |        158 |        241 | CyberBahamut         |
//| Creature_02     |             199 |        199 |        198 | Bahamut              |
//| Creature_03     |             232 |        232 |        179 | CyberBahamut         |
//| Creature_04     |             209 |        209 |        209 | Ceffyl               |
//| Creature_05     |             214 |        214 |        139 | Bahamut              |
//| Creature_06     |             190 |        190 |        157 | Bahamut              |
//| Creature_07     |             235 |        235 |        128 | Ceffyl               |
//| Creature_08     |             178 |        178 |        160 | CyberBahamut         |
//| Creature_09     |             237 |        237 |        133 | Bahamut              |
//| Creature_10     |             133 |        133 |        151 | CyberBahamut         |
//| Creature_11     |             208 |        208 |        186 | Ceffyl               |
//| Creature_12     |             236 |        236 |        128 | Bahamut              |
//| Creature_13     |             151 |        151 |        161 | Ceffyl               |
//| Creature_14     |             201 |        201 |        178 | CyberBahamut         |
//| Creature_15     |             178 |        178 |        191 | Bahamut              |
//| Creature_16     |             137 |        137 |        149 | Nuggle               |
//| Creature_17     |             231 |        231 |        156 | Bahamut              |
//| Creature_18     |             180 |        180 |        216 | Bahamut              |
//| Creature_19     |             142 |        142 |        241 | Bahamut              |
//| Creature_20     |             222 |        222 |        224 | Ceffyl               |
//| Creature_21     |             226 |        226 |        239 | Ceffyl               |
//| Creature_22     |             174 |        174 |        157 | Ceffyl               |
//| Creature_23     |             222 |        222 |        204 | CyberBahamut         |
//| Creature_24     |             133 |        133 |        200 | Bahamut              |
//| Creature_25     |             218 |        218 |        186 | Ceffyl               |
//| Creature_26     |             211 |        211 |        247 | Nuggle               |
//| Creature_27     |             171 |        171 |        177 | Bahamut              |
//| Creature_28     |             128 |        128 |        149 | Ceffyl               |
//| Creature_29     |             228 |        228 |        245 | Ceffyl               |
//| Creature_30     |             237 |        237 |        130 | Nuggle               |
//| Creature_31     |             217 |        217 |        160 | Ceffyl               |
//| Creature_32     |             166 |        166 |        165 | Bahamut              |
//| Creature_33     |             220 |        220 |        242 | Bahamut              |
//| Creature_34     |             243 |        243 |        183 | Ceffyl               |
//| Creature_35     |             191 |        191 |        176 | Nuggle               |
//| Creature_36     |             171 |        171 |        244 | Nuggle               |
//| Creature_37     |             239 |        239 |        231 | Nuggle               |
//| Creature_38     |             130 |        130 |        148 | Nuggle               |
//| Creature_39     |             239 |        239 |        134 | CyberBahamut         |
//| Creature_40     |             221 |        221 |        210 | Ceffyl               |
//| Creature_41     |             221 |        221 |        160 | CyberBahamut         |
//| Creature_42     |             237 |        237 |        168 | Ceffyl               |
//| Creature_43     |             188 |        188 |        159 | Bahamut              |
//| Creature_44     |             162 |        162 |        128 | Ceffyl               |
//| Creature_45     |             210 |        210 |        199 | Ceffyl               |
//| Creature_46     |             159 |        159 |        144 | CyberBahamut         |
//| Creature_47     |             185 |        185 |        194 | Ceffyl               |
//| Creature_48     |             124 |        124 |        142 | Ceffyl               |
//| Creature_49     |             122 |        122 |        235 | Ceffyl               |
//| Creature_50     |             134 |        134 |        128 | Ceffyl               |
//
//
//Army B:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_01     |             125 |        125 |        121 | Bahamut              |
//| Creature_02     |             124 |        124 |        242 | Nuggle               |
//| Creature_03     |             243 |        243 |        217 | Bahamut              |
//| Creature_04     |             171 |        171 |        177 | Nuggle               |
//| Creature_05     |             209 |        209 |        163 | Nuggle               |
//| Creature_06     |             121 |        121 |        164 | CyberBahamut         |
//| Creature_07     |             196 |        196 |        175 | Ceffyl               |
//| Creature_08     |             181 |        181 |        250 | Nuggle               |
//| Creature_09     |             137 |        137 |        184 | Ceffyl               |
//| Creature_10     |             153 |        153 |        161 | Ceffyl               |
//| Creature_11     |             197 |        197 |        238 | Nuggle               |
//| Creature_12     |             171 |        171 |        124 | Nuggle               |
//| Creature_13     |             177 |        177 |        214 | Bahamut              |
//| Creature_14     |             152 |        152 |        204 | Nuggle               |
//| Creature_15     |             164 |        164 |        129 | CyberBahamut         |
//| Creature_16     |             207 |        207 |        235 | Nuggle               |
//| Creature_17     |             192 |        192 |        199 | Ceffyl               |
//| Creature_18     |             217 |        217 |        144 | Ceffyl               |
//| Creature_19     |             207 |        207 |        206 | CyberBahamut         |
//| Creature_20     |             150 |        150 |        187 | Bahamut              |
//| Creature_21     |             174 |        174 |        222 | Nuggle               |
//| Creature_22     |             122 |        122 |        152 | Bahamut              |
//| Creature_23     |             230 |        230 |        183 | Ceffyl               |
//| Creature_24     |             203 |        203 |        215 | Ceffyl               |
//| Creature_25     |             162 |        162 |        172 | Ceffyl               |
//| Creature_26     |             244 |        244 |        229 | CyberBahamut         |
//| Creature_27     |             160 |        160 |        192 | Nuggle               |
//| Creature_28     |             249 |        249 |        200 | Nuggle               |
//| Creature_29     |             218 |        218 |        200 | Bahamut              |
//| Creature_30     |             240 |        240 |        214 | Bahamut              |
//| Creature_31     |             126 |        126 |        167 | CyberBahamut         |
//| Creature_32     |             167 |        167 |        194 | CyberBahamut         |
//| Creature_33     |             212 |        212 |        156 | Bahamut              |
//| Creature_34     |             179 |        179 |        188 | CyberBahamut         |
//| Creature_35     |             167 |        167 |        185 | Ceffyl               |
//| Creature_36     |             120 |        120 |        153 | Bahamut              |
//| Creature_37     |             162 |        162 |        246 | CyberBahamut         |
//| Creature_38     |             198 |        198 |        182 | Bahamut              |
//| Creature_39     |             165 |        165 |        133 | Bahamut              |
//| Creature_40     |             164 |        164 |        194 | CyberBahamut         |
//| Creature_41     |             180 |        180 |        226 | Ceffyl               |
//| Creature_42     |             130 |        130 |        246 | Bahamut              |
//| Creature_43     |             169 |        169 |        245 | Ceffyl               |
//| Creature_44     |             161 |        161 |        223 | Ceffyl               |
//| Creature_45     |             135 |        135 |        244 | CyberBahamut         |
//| Creature_46     |             143 |        143 |        179 | CyberBahamut         |
//| Creature_47     |             243 |        243 |        199 | CyberBahamut         |
//| Creature_48     |             218 |        218 |        158 | Nuggle               |
//| Creature_49     |             177 |        177 |        140 | Bahamut              |
//| Creature_50     |             228 |        228 |        194 | CyberBahamut         |
//
//
//| Attacker             | Damage     | Army                 |    Defender             | Health     | Army                 |
//--------------------------------------------------------------------------------------------------------------------------
//| Creature_50          |         31 | A                    |    Creature_50          |        197 | B                    |
//| Creature_50          |        386 | B                    |    Creature_50          |          0 | A                    |
//| Creature_49          |        163 | A                    |    Creature_49          |         14 | B                    |
//| Creature_49          |         70 | B                    |    Creature_49          |         52 | A                    |
//| Creature_49          |        104 | A                    |    Creature_49          |          0 | B                    |
//| Creature_48          |        300 | B                    |    Creature_48          |          0 | A                    |
//| Creature_47          |         73 | A                    |    Creature_47          |        170 | B                    |
//| Creature_47          |        132 | B                    |    Creature_47          |         53 | A                    |
//| Creature_47          |         83 | A                    |    Creature_47          |         87 | B                    |
//| Creature_47          |        302 | B                    |    Creature_47          |          0 | A                    |
//| Creature_46          |        240 | B                    |    Creature_46          |          0 | A                    |
//| Creature_45          |        264 | B                    |    Creature_45          |          0 | A                    |
//| Creature_44          |         33 | A                    |    Creature_44          |        128 | B                    |
//| Creature_44          |          3 | B                    |    Creature_44          |        159 | A                    |
//| Creature_44          |         53 | A                    |    Creature_44          |         75 | B                    |
//| Creature_44          |        246 | B                    |    Creature_44          |          0 | A                    |
//| Creature_43          |         93 | B                    |    Creature_43          |         95 | A                    |
//| Creature_43          |        218 | A                    |    Creature_43          |          0 | B                    |
//| Creature_42          |         25 | A                    |    Creature_42          |        105 | B                    |
//| Creature_42          |        324 | B                    |    Creature_42          |          0 | A                    |
//| Creature_41          |        294 | A                    |    Creature_41          |          0 | B                    |
//| Creature_40          |        214 | B                    |    Creature_40          |          7 | A                    |
//| Creature_40          |        146 | A                    |    Creature_40          |         18 | B                    |
//| Creature_40          |        302 | B                    |    Creature_40          |          0 | A                    |
//| Creature_39          |        146 | B                    |    Creature_39          |         93 | A                    |
//| Creature_39          |         88 | A                    |    Creature_39          |         77 | B                    |
//| Creature_39          |         22 | B                    |    Creature_39          |         71 | A                    |
//| Creature_39          |         96 | A                    |    Creature_39          |          0 | B                    |
//| Creature_38          |         42 | B                    |    Creature_38          |         88 | A                    |
//| Creature_38          |        166 | A                    |    Creature_38          |         32 | B                    |
//| Creature_38          |        284 | B                    |    Creature_38          |          0 | A                    |
//| Creature_37          |        218 | A                    |    Creature_37          |          0 | B                    |
//| Creature_36          |         70 | B                    |    Creature_36          |        101 | A                    |
//| Creature_36          |        122 | A                    |    Creature_36          |          0 | B                    |
//| Creature_35          |        173 | B                    |    Creature_35          |         18 | A                    |
//| Creature_35          |        156 | A                    |    Creature_35          |         11 | B                    |
//| Creature_35          |        130 | B                    |    Creature_35          |          0 | A                    |
//| Creature_34          |         88 | B                    |    Creature_34          |        155 | A                    |
//| Creature_34          |          4 | A                    |    Creature_34          |        175 | B                    |
//| Creature_34          |        288 | B                    |    Creature_34          |          0 | A                    |
//| Creature_33          |        204 | B                    |    Creature_33          |         16 | A                    |
//| Creature_33          |        244 | A                    |    Creature_33          |          0 | B                    |
//| Creature_32          |        358 | B                    |    Creature_32          |          0 | A                    |
//| Creature_31          |          4 | B                    |    Creature_31          |        213 | A                    |
//| Creature_31          |         93 | A                    |    Creature_31          |         33 | B                    |
//| Creature_31          |        318 | B                    |    Creature_31          |          0 | A                    |
//| Creature_30          |         62 | B                    |    Creature_30          |        175 | A                    |
//| Creature_30          |         19 | A                    |    Creature_30          |        221 | B                    |
//| Creature_30          |        246 | B                    |    Creature_30          |          0 | A                    |
//| Creature_29          |        182 | A                    |    Creature_29          |         36 | B                    |
//| Creature_29          |        304 | B                    |    Creature_29          |          0 | A                    |
//| Creature_28          |        133 | B                    |    Creature_28          |          0 | A                    |
//| Creature_27          |        151 | B                    |    Creature_27          |         20 | A                    |
//| Creature_27          |         42 | A                    |    Creature_27          |        118 | B                    |
//| Creature_27          |        174 | B                    |    Creature_27          |          0 | A                    |
//| Creature_26          |        400 | A                    |    Creature_26          |          0 | B                    |
//| Creature_25          |         32 | B                    |    Creature_25          |        186 | A                    |
//| Creature_25          |        186 | A                    |    Creature_25          |          0 | B                    |
//| Creature_24          |          2 | B                    |    Creature_24          |        131 | A                    |
//| Creature_24          |         14 | A                    |    Creature_24          |        189 | B                    |
//| Creature_24          |        204 | B                    |    Creature_24          |          0 | A                    |
//| Creature_23          |        170 | B                    |    Creature_23          |         52 | A                    |
//| Creature_23          |        342 | A                    |    Creature_23          |          0 | B                    |
//| Creature_22          |        208 | B                    |    Creature_22          |          0 | A                    |
//| Creature_21          |        219 | A                    |    Creature_21          |          0 | B                    |
//| Creature_20          |        368 | B                    |    Creature_20          |          0 | A                    |
//| Creature_19          |        306 | A                    |    Creature_19          |          0 | B                    |
//| Creature_18          |        344 | A                    |    Creature_18          |          0 | B                    |
//| Creature_17          |         84 | A                    |    Creature_17          |        108 | B                    |
//| Creature_17          |        131 | B                    |    Creature_17          |        100 | A                    |
//| Creature_17          |        214 | A                    |    Creature_17          |          0 | B                    |
//| Creature_16          |        262 | B                    |    Creature_16          |          0 | A                    |
//| Creature_15          |        308 | A                    |    Creature_15          |          0 | B                    |
//| Creature_14          |        332 | A                    |    Creature_14          |          0 | B                    |
//| Creature_13          |        418 | B                    |    Creature_13          |          0 | A                    |
//| Creature_12          |         75 | B                    |    Creature_12          |        161 | A                    |
//| Creature_12          |        116 | A                    |    Creature_12          |         55 | B                    |
//| Creature_12          |        117 | B                    |    Creature_12          |         44 | A                    |
//| Creature_12          |        214 | A                    |    Creature_12          |          0 | B                    |
//| Creature_11          |          2 | A                    |    Creature_11          |        195 | B                    |
//| Creature_11          |         98 | B                    |    Creature_11          |        110 | A                    |
//| Creature_11          |         72 | A                    |    Creature_11          |        123 | B                    |
//| Creature_11          |        194 | B                    |    Creature_11          |          0 | A                    |
//| Creature_10          |         91 | B                    |    Creature_10          |         42 | A                    |
//| Creature_10          |        220 | A                    |    Creature_10          |          0 | B                    |
//| Creature_09          |         53 | B                    |    Creature_09          |        184 | A                    |
//| Creature_09          |        222 | A                    |    Creature_09          |          0 | B                    |
//| Creature_08          |        282 | A                    |    Creature_08          |          0 | B                    |
//| Creature_07          |        126 | A                    |    Creature_07          |         70 | B                    |
//| Creature_07          |        173 | B                    |    Creature_07          |         62 | A                    |
//| Creature_07          |        126 | A                    |    Creature_07          |          0 | B                    |
//| Creature_06          |        284 | B                    |    Creature_06          |          0 | A                    |
//| Creature_05          |        162 | B                    |    Creature_05          |         52 | A                    |
//| Creature_05          |        132 | A                    |    Creature_05          |         77 | B                    |
//| Creature_05          |         26 | B                    |    Creature_05          |         26 | A                    |
//| Creature_05          |        232 | A                    |    Creature_05          |          0 | B                    |
//| Creature_04          |        113 | B                    |    Creature_04          |         96 | A                    |
//| Creature_04          |        191 | A                    |    Creature_04          |          0 | B                    |
//| Creature_03          |        140 | B                    |    Creature_03          |         92 | A                    |
//| Creature_03          |        254 | A                    |    Creature_03          |          0 | B                    |
//| Creature_02          |        172 | A                    |    Creature_02          |          0 | B                    |
//| Creature_01          |        196 | B                    |    Creature_01          |          0 | A                    |
//
//
//Winner: B
//
//
//Army A:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_01     |               0 |        158 |        241 | CyberBahamut         |
//| Creature_02     |             199 |        199 |        198 | Bahamut              |
//| Creature_03     |              92 |        232 |        179 | CyberBahamut         |
//| Creature_04     |              96 |        209 |        209 | Ceffyl               |
//| Creature_05     |              26 |        214 |        139 | Bahamut              |
//| Creature_06     |               0 |        190 |        157 | Bahamut              |
//| Creature_07     |              62 |        235 |        128 | Ceffyl               |
//| Creature_08     |             178 |        178 |        160 | CyberBahamut         |
//| Creature_09     |             184 |        237 |        133 | Bahamut              |
//| Creature_10     |              42 |        133 |        151 | CyberBahamut         |
//| Creature_11     |               0 |        208 |        186 | Ceffyl               |
//| Creature_12     |              44 |        236 |        128 | Bahamut              |
//| Creature_13     |               0 |        151 |        161 | Ceffyl               |
//| Creature_14     |             201 |        201 |        178 | CyberBahamut         |
//| Creature_15     |             178 |        178 |        191 | Bahamut              |
//| Creature_16     |               0 |        137 |        149 | Nuggle               |
//| Creature_17     |             100 |        231 |        156 | Bahamut              |
//| Creature_18     |             180 |        180 |        216 | Bahamut              |
//| Creature_19     |             142 |        142 |        241 | Bahamut              |
//| Creature_20     |               0 |        222 |        224 | Ceffyl               |
//| Creature_21     |             226 |        226 |        239 | Ceffyl               |
//| Creature_22     |               0 |        174 |        157 | Ceffyl               |
//| Creature_23     |              52 |        222 |        204 | CyberBahamut         |
//| Creature_24     |               0 |        133 |        200 | Bahamut              |
//| Creature_25     |             186 |        218 |        186 | Ceffyl               |
//| Creature_26     |             211 |        211 |        247 | Nuggle               |
//| Creature_27     |               0 |        171 |        177 | Bahamut              |
//| Creature_28     |               0 |        128 |        149 | Ceffyl               |
//| Creature_29     |               0 |        228 |        245 | Ceffyl               |
//| Creature_30     |               0 |        237 |        130 | Nuggle               |
//| Creature_31     |               0 |        217 |        160 | Ceffyl               |
//| Creature_32     |               0 |        166 |        165 | Bahamut              |
//| Creature_33     |              16 |        220 |        242 | Bahamut              |
//| Creature_34     |               0 |        243 |        183 | Ceffyl               |
//| Creature_35     |               0 |        191 |        176 | Nuggle               |
//| Creature_36     |             101 |        171 |        244 | Nuggle               |
//| Creature_37     |             239 |        239 |        231 | Nuggle               |
//| Creature_38     |               0 |        130 |        148 | Nuggle               |
//| Creature_39     |              71 |        239 |        134 | CyberBahamut         |
//| Creature_40     |               0 |        221 |        210 | Ceffyl               |
//| Creature_41     |             221 |        221 |        160 | CyberBahamut         |
//| Creature_42     |               0 |        237 |        168 | Ceffyl               |
//| Creature_43     |              95 |        188 |        159 | Bahamut              |
//| Creature_44     |               0 |        162 |        128 | Ceffyl               |
//| Creature_45     |               0 |        210 |        199 | Ceffyl               |
//| Creature_46     |               0 |        159 |        144 | CyberBahamut         |
//| Creature_47     |               0 |        185 |        194 | Ceffyl               |
//| Creature_48     |               0 |        124 |        142 | Ceffyl               |
//| Creature_49     |              52 |        122 |        235 | Ceffyl               |
//| Creature_50     |               0 |        134 |        128 | Ceffyl               |
//
//
//Army B:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_01     |             125 |        125 |        121 | Bahamut              |
//| Creature_02     |               0 |        124 |        242 | Nuggle               |
//| Creature_03     |               0 |        243 |        217 | Bahamut              |
//| Creature_04     |               0 |        171 |        177 | Nuggle               |
//| Creature_05     |               0 |        209 |        163 | Nuggle               |
//| Creature_06     |             121 |        121 |        164 | CyberBahamut         |
//| Creature_07     |               0 |        196 |        175 | Ceffyl               |
//| Creature_08     |               0 |        181 |        250 | Nuggle               |
//| Creature_09     |               0 |        137 |        184 | Ceffyl               |
//| Creature_10     |               0 |        153 |        161 | Ceffyl               |
//| Creature_11     |             123 |        197 |        238 | Nuggle               |
//| Creature_12     |               0 |        171 |        124 | Nuggle               |
//| Creature_13     |             177 |        177 |        214 | Bahamut              |
//| Creature_14     |               0 |        152 |        204 | Nuggle               |
//| Creature_15     |               0 |        164 |        129 | CyberBahamut         |
//| Creature_16     |             207 |        207 |        235 | Nuggle               |
//| Creature_17     |               0 |        192 |        199 | Ceffyl               |
//| Creature_18     |               0 |        217 |        144 | Ceffyl               |
//| Creature_19     |               0 |        207 |        206 | CyberBahamut         |
//| Creature_20     |             150 |        150 |        187 | Bahamut              |
//| Creature_21     |               0 |        174 |        222 | Nuggle               |
//| Creature_22     |             122 |        122 |        152 | Bahamut              |
//| Creature_23     |               0 |        230 |        183 | Ceffyl               |
//| Creature_24     |             189 |        203 |        215 | Ceffyl               |
//| Creature_25     |               0 |        162 |        172 | Ceffyl               |
//| Creature_26     |               0 |        244 |        229 | CyberBahamut         |
//| Creature_27     |             118 |        160 |        192 | Nuggle               |
//| Creature_28     |             249 |        249 |        200 | Nuggle               |
//| Creature_29     |              36 |        218 |        200 | Bahamut              |
//| Creature_30     |             221 |        240 |        214 | Bahamut              |
//| Creature_31     |              33 |        126 |        167 | CyberBahamut         |
//| Creature_32     |             167 |        167 |        194 | CyberBahamut         |
//| Creature_33     |               0 |        212 |        156 | Bahamut              |
//| Creature_34     |             175 |        179 |        188 | CyberBahamut         |
//| Creature_35     |              11 |        167 |        185 | Ceffyl               |
//| Creature_36     |               0 |        120 |        153 | Bahamut              |
//| Creature_37     |               0 |        162 |        246 | CyberBahamut         |
//| Creature_38     |              32 |        198 |        182 | Bahamut              |
//| Creature_39     |               0 |        165 |        133 | Bahamut              |
//| Creature_40     |              18 |        164 |        194 | CyberBahamut         |
//| Creature_41     |               0 |        180 |        226 | Ceffyl               |
//| Creature_42     |             105 |        130 |        246 | Bahamut              |
//| Creature_43     |               0 |        169 |        245 | Ceffyl               |
//| Creature_44     |              75 |        161 |        223 | Ceffyl               |
//| Creature_45     |             135 |        135 |        244 | CyberBahamut         |
//| Creature_46     |             143 |        143 |        179 | CyberBahamut         |
//| Creature_47     |              87 |        243 |        199 | CyberBahamut         |
//| Creature_48     |             218 |        218 |        158 | Nuggle               |
//| Creature_49     |               0 |        177 |        140 | Bahamut              |
//| Creature_50     |             197 |        228 |        194 | CyberBahamut         |
//









//TestCase2: Sort Function by Name
//Options:
//        1. Play
//        2. Sort Creatures by Field
//        3. Filter Creatures by Health Range
//        4. Quit
//
//2
//
//
//Sort Options:
//        1. Name
//        2. Current Health
//        3. Max Health
//        4. Strength
//        5. Type
//        6. None: Go back to outer menu
//
//1
//
//
//
//Army A:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_01     |             168 |        168 |        140 | CyberBahamut         |
//| Creature_02     |              86 |        173 |        230 | Ceffyl               |
//| Creature_03     |               0 |        172 |        141 | Nuggle               |
//| Creature_04     |               0 |        226 |        145 | Bahamut              |
//| Creature_05     |               0 |        137 |        130 | Ceffyl               |
//| Creature_06     |               0 |        149 |        137 | Ceffyl               |
//| Creature_07     |             140 |        168 |        145 | CyberBahamut         |
//| Creature_08     |              90 |        224 |        218 | Bahamut              |
//| Creature_09     |             122 |        122 |        206 | Bahamut              |
//| Creature_10     |               8 |        242 |        133 | Bahamut              |
//
//
//Army B:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_01     |               0 |        175 |        223 | Bahamut              |
//| Creature_02     |               0 |        155 |        197 | Ceffyl               |
//| Creature_03     |             211 |        211 |        223 | Bahamut              |
//| Creature_04     |             174 |        174 |        190 | CyberBahamut         |
//| Creature_05     |              22 |        166 |        169 | Bahamut              |
//| Creature_06     |              12 |        125 |        197 | Ceffyl               |
//| Creature_07     |               0 |        247 |        212 | Bahamut              |
//| Creature_08     |               0 |        245 |        165 | Ceffyl               |
//| Creature_09     |               0 |        226 |        176 | Nuggle               |
//| Creature_10     |               0 |        238 |        181 | Bahamut              |










////TestCase3: Sort Function by Current Health
//Army A:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_03     |               0 |        172 |        141 | Nuggle               |
//| Creature_04     |               0 |        226 |        145 | Bahamut              |
//| Creature_05     |               0 |        137 |        130 | Ceffyl               |
//| Creature_06     |               0 |        149 |        137 | Ceffyl               |
//| Creature_10     |               8 |        242 |        133 | Bahamut              |
//| Creature_02     |              86 |        173 |        230 | Ceffyl               |
//| Creature_08     |              90 |        224 |        218 | Bahamut              |
//| Creature_09     |             122 |        122 |        206 | Bahamut              |
//| Creature_07     |             140 |        168 |        145 | CyberBahamut         |
//| Creature_01     |             168 |        168 |        140 | CyberBahamut         |
//
//
//Army B:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_01     |               0 |        175 |        223 | Bahamut              |
//| Creature_02     |               0 |        155 |        197 | Ceffyl               |
//| Creature_07     |               0 |        247 |        212 | Bahamut              |
//| Creature_08     |               0 |        245 |        165 | Ceffyl               |
//| Creature_09     |               0 |        226 |        176 | Nuggle               |
//| Creature_10     |               0 |        238 |        181 | Bahamut              |
//| Creature_06     |              12 |        125 |        197 | Ceffyl               |
//| Creature_05     |              22 |        166 |        169 | Bahamut              |
//| Creature_04     |             174 |        174 |        190 | CyberBahamut         |
//| Creature_03     |             211 |        211 |        223 | Bahamut              |
//







////TestCase4: Sort Function by Max Health
//Army A:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_09     |             122 |        122 |        206 | Bahamut              |
//| Creature_05     |               0 |        137 |        130 | Ceffyl               |
//| Creature_06     |               0 |        149 |        137 | Ceffyl               |
//| Creature_07     |             140 |        168 |        145 | CyberBahamut         |
//| Creature_01     |             168 |        168 |        140 | CyberBahamut         |
//| Creature_03     |               0 |        172 |        141 | Nuggle               |
//| Creature_02     |              86 |        173 |        230 | Ceffyl               |
//| Creature_08     |              90 |        224 |        218 | Bahamut              |
//| Creature_04     |               0 |        226 |        145 | Bahamut              |
//| Creature_10     |               8 |        242 |        133 | Bahamut              |
//
//
//Army B:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_06     |              12 |        125 |        197 | Ceffyl               |
//| Creature_02     |               0 |        155 |        197 | Ceffyl               |
//| Creature_05     |              22 |        166 |        169 | Bahamut              |
//| Creature_04     |             174 |        174 |        190 | CyberBahamut         |
//| Creature_01     |               0 |        175 |        223 | Bahamut              |
//| Creature_03     |             211 |        211 |        223 | Bahamut              |
//| Creature_09     |               0 |        226 |        176 | Nuggle               |
//| Creature_10     |               0 |        238 |        181 | Bahamut              |
//| Creature_08     |               0 |        245 |        165 | Ceffyl               |
//| Creature_07     |               0 |        247 |        212 | Bahamut              |
//
//







////TestCase5: Sort Function by Strength
//Army A:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_05     |               0 |        137 |        130 | Ceffyl               |
//| Creature_10     |               8 |        242 |        133 | Bahamut              |
//| Creature_06     |               0 |        149 |        137 | Ceffyl               |
//| Creature_01     |             168 |        168 |        140 | CyberBahamut         |
//| Creature_03     |               0 |        172 |        141 | Nuggle               |
//| Creature_07     |             140 |        168 |        145 | CyberBahamut         |
//| Creature_04     |               0 |        226 |        145 | Bahamut              |
//| Creature_09     |             122 |        122 |        206 | Bahamut              |
//| Creature_08     |              90 |        224 |        218 | Bahamut              |
//| Creature_02     |              86 |        173 |        230 | Ceffyl               |
//
//
//Army B:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_08     |               0 |        245 |        165 | Ceffyl               |
//| Creature_05     |              22 |        166 |        169 | Bahamut              |
//| Creature_09     |               0 |        226 |        176 | Nuggle               |
//| Creature_10     |               0 |        238 |        181 | Bahamut              |
//| Creature_04     |             174 |        174 |        190 | CyberBahamut         |
//| Creature_06     |              12 |        125 |        197 | Ceffyl               |
//| Creature_02     |               0 |        155 |        197 | Ceffyl               |
//| Creature_07     |               0 |        247 |        212 | Bahamut              |
//| Creature_01     |               0 |        175 |        223 | Bahamut              |
//| Creature_03     |             211 |        211 |        223 | Bahamut              |
//








////TestCase6: Sort Function by Type
//Army A:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_05     |               0 |        137 |        130 | Ceffyl               |
//| Creature_06     |               0 |        149 |        137 | Ceffyl               |
//| Creature_02     |              86 |        173 |        230 | Ceffyl               |
//| Creature_10     |               8 |        242 |        133 | Bahamut              |
//| Creature_04     |               0 |        226 |        145 | Bahamut              |
//| Creature_09     |             122 |        122 |        206 | Bahamut              |
//| Creature_08     |              90 |        224 |        218 | Bahamut              |
//| Creature_01     |             168 |        168 |        140 | CyberBahamut         |
//| Creature_07     |             140 |        168 |        145 | CyberBahamut         |
//| Creature_03     |               0 |        172 |        141 | Nuggle               |
//
//
//Army B:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_08     |               0 |        245 |        165 | Ceffyl               |
//| Creature_06     |              12 |        125 |        197 | Ceffyl               |
//| Creature_02     |               0 |        155 |        197 | Ceffyl               |
//| Creature_05     |              22 |        166 |        169 | Bahamut              |
//| Creature_10     |               0 |        238 |        181 | Bahamut              |
//| Creature_07     |               0 |        247 |        212 | Bahamut              |
//| Creature_01     |               0 |        175 |        223 | Bahamut              |
//| Creature_03     |             211 |        211 |        223 | Bahamut              |
//| Creature_04     |             174 |        174 |        190 | CyberBahamut         |
//| Creature_09     |               0 |        226 |        176 | Nuggle               |
//
//





////TestCase7: Sort Function Quit
//Options:
//        1. Play
//        2. Sort Creatures by Field
//        3. Filter Creatures by Health Range
//        4. Quit
//
//2
//
//
//Sort Options:
//        1. Name
//        2. Current Health
//        3. Max Health
//        4. Strength
//        5. Type
//        6. None: Go back to outer menu
//
//6
//Returning To Outer Menu







//TestCase8: Filter View By Health
//Options:
//        1. Play
//        2. Sort Creatures by Field
//        3. Filter Creatures by Health Range
//        4. Quit
//
//3
//Please enter minimum health
//        50
//Please enter maximum health{must be greater than minimum health}
//        200
//
//
//
//Army A:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_03     |              90 |        232 |        179 | CyberBahamut         |
//| Creature_06     |             190 |        190 |        157 | Bahamut              |
//| Creature_08     |             178 |        178 |        160 | CyberBahamut         |
//
//
//
//
//Army B:
//
//| Name            | Current Health  | Max Health | Strength   | Type                 |
//--------------------------------------------------------------------------------------
//| Creature_02     |              54 |        236 |        128 | Bahamut              |
//| Creature_04     |             113 |        201 |        178 | CyberBahamut         |
//| Creature_07     |             167 |        231 |        156 | Bahamut              |
//| Creature_10     |             120 |        222 |        224 | Ceffyl               |







//TestCase9: Quit
//Options:
//        1. Play
//        2. Sort Creatures by Field
//        3. Filter Creatures by Health Range
//        4. Quit
//
//4
//
//Program now closed
