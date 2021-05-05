#include "ParseString.h"

bool ParseString::IsEqualsKeyWord(std::string keyWord)
{
    return (this->Equals(keyWord, stringInputUser.substr(0, indexStr)));
}
