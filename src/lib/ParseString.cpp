#include <lib/ParseString.h>

/*

Internal:

static

or

namespace {

}

*/

static std::string ToLower(std::string str) const
{
    for (int index = 0; index < ((int)str.length()); index++) {
        if ((int)str[index] > 64 && (int)str[index] < 91) {
            str[index] += 32;
        }
    }

    return str;
}

// Метод сравнения двух строк
// В данном случае не просто сравнивает ,
// а еще преобразует к единому регистру
static bool Equals(const std::string& str_1, const std::string& str_2)
{
    return ToLower(str_1) == ToLower(str_2);
}


