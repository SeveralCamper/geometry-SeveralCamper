#include "ParseString.h"
   
bool ParseString::IsEqualsKeyWord(std::string keyWord)
{
    if (this->Equals(keyWord, stringInputUser.substr(0, indexStr)))
        return true;
    return false;
}
