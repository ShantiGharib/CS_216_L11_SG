#include "GlobalFunctions.h"
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>


void HandleInvalidOption() {

    std::cout << "\nInvalid option selected\n";

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


std::string PrintSeparationLine(int width) {

    std::ostringstream result;

    result << std::setfill('-') << std::setw(width) << "" << std::setfill(' ') << "\n";

    return result.str();
}


void NormalizeString(std::string& str) {

    static constexpr const int CASE_DIFFERENCE{'A' - 'a'};
    static constexpr const char UNDERSCORE{'_'}, SPACE{' '}, LOW_A{'a'}, LOW_Z{'z'};

    for (size_t i = 0; i < str.size(); ++i) {

        if (LOW_A <= str[i] && str[i] <= LOW_Z) {
            str[i] += CASE_DIFFERENCE;
        }
        else if (str[i] == UNDERSCORE) {
            str[i] = SPACE;
        }

    }
}


void DisplayMainMenu() {

    std::cout << "\n\nOptions:"

        "\n\t1. Play"

        "\n\t2. Sort Creatures by Field"

        "\n\t3. Filter Creatures by Health Range"

        "\n\t4. Quit\n\n";
}

