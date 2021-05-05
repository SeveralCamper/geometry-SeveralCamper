#include "ParseString.h"

bool ParseString::Equals(std::string str_1, std::string str_2)
{
    if (ToLower(str_1) == ToLower(str_2))
        return true;
    return false;
}
