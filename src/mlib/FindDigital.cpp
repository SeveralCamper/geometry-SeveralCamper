#include "ParseString.h"

bool ParseString::FindDigital()
{
    // Ищем цифру.
    for (int index = indexStr + 1; index < ((int)stringInputUser.length());
         index++) {
        if (!IsWhitespace(index)) {
            indexStr = index;
            return (IsDigitalSymbol(index)); 
        }
    }

    // Если по неведомым причинам попали сюда, хоть и не должны
    // Тут вообще много вариантов было. решил сделать так.
    return false;
}
