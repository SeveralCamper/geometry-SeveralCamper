#include "ParseString.h"

std::string ParseString::SubStr(int startPos, int endPos)
{
    return stringInputUser.substr(startPos, endPos);
}
