#include "ParseString.h"

bool ParseString::IsDigitalSymbol(int index)
{
    if ((int)stringInputUser[index] > 47 && (int)stringInputUser[index] < 59)
        return true;
    return false;
}
