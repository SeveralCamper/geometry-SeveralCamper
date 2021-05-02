#include "ParseString.h"

std::string ParseString::ToLower(std::string str)
{
    for (int index = 0; index < ((int)str.length()); index++) {
        if ((int)str[index] > 64 && (int)str[index] < 91) {
            str[index] += 32;
        }
    }

    return str;
}
