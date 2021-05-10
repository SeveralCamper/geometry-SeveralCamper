#include "ParseString.h"

bool ParseString::IsDigitalSymbol(int index)
{
    return ((int)stringInputUser[index] > 47
            && (int)stringInputUser[index] < 59);
}