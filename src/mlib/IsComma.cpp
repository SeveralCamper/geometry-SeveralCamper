#include "ParseString.h"

bool ParseString::IsComma()
{
    // Ищем запятую.
    for (int index = indexStr + 1; index < ((int)stringInputUser.length());
         index++) {
        if (!IsWhitespace(index)) {
            indexStr = index;
            return (stringInputUser[index] == ',');
        }
    }

    return false;
}
