#include "ParseString.h"

bool ParseString::Equals(std::string str_1, std::string str_2)
{
    return (ToLower(str_1) == ToLower(str_2));
}
