#include "ParseString.h"

bool ParseString::IsNotChar(int index)
{
    // Если символ отличный от буквы
    if (((int)stringInputUser[index] > 91 && (int)stringInputUser[index] < 96)
        || (int)stringInputUser[index] < 64
        || (int)stringInputUser[index] > 123)
        return true;

    return false;
}
