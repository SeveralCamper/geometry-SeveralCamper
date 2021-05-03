#include "ParseString.h"

int ParseString::FindNumber()
{
    stringNumber = "";

    for (int index = indexStr; index < ((int)stringInputUser.length());
         index++) {
        // Если Это цифра
        if (IsDigitalSymbol(index)) {
            // Добавляем найденую цифру к строке числа
            stringNumber += stringInputUser[index];
        }

        // Если пробел,
        if (IsWhitespace(index)
            || index == ((int)stringInputUser.length()) - 1) {
            // Сохраняем индекс
            indexStr = index;

            // И выходим из цикла
            return 0;
        }

        //  Если всё кроме пробела и цифры
        if (!IsDigitalSymbol(index) && !IsWhitespace(index)) {
            // Сохраняем индекс и возвращем ошибку
            indexStr = index;
            return 1;
        }
    }

    // Если по неведомым причинам попали сюда, хоть и не должны
    return -1;
}
