#include "ParseString.h"

void ParseString::FindFirstCharDifferentFrom()
{
    for (int i = 0; i < ((int)stringInputUser.length()); i++) {
        // Если получили символ отличный от буквы
        if (IsNotChar(i)) {
            // Запоминаем индекс, на котором остановились
            indexStr = i;

            // И выходим из цикла
            break;
        }
    }
}
