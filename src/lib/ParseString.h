#include <iostream>
#include <stdio.h>
#include <string.h>

// Объявляем класс ParseString, в котором будем описывать методы работы со
// строкой
class ParseString {
private:
    //Скрыл поле пользовательской строки от изменения вне класса
    // Строка введенная пользователем

    std::string stringInputUser;

    //Строка хранящая число
    std::string stringNumber;

public:
    // Хранит индекс строки
    int indexStr = 0;

    // Метод для преобразования букв к нижнему регистру
    std::string ToLower(std::string str);

    // Проверка на символ отличный от буквы
    bool IsNotChar(int index);

    // Метод возвращающий истину если ключевое слово совпало
    bool IsEqualsKeyWord(std::string keyWord);

    // Если сивол - цифра
    bool IsDigitalSymbol(int index);

    // Проверка на пробел
    // Если пробел - true, если нет то false
    bool IsWhitespace(int index);

    // Открытая скобка или нет
    bool IsOpenParenthesis();

    // Функция проверки введенной открытой скобки
    bool IsCloseParenthesis();

    // Метод ищет запятую
    bool IsComma();

    // Метод который ищет первый символ не совпадающий с буквой
    void FindFirstCharDifferentFrom();

    // Метод сравнения двух строк
    // В данном случае не просто сравнивает ,
    // а еще преобразует к единому регистру
    bool Equals(std::string str_1, std::string str_2);

    // Метод устанавливающий в поле stringInputUser введную строку пользователя
    void SetString(std::string str);

    // Вернуть длину строки
    int Lenght()
    {
        return stringInputUser.length();
    }

    // Возвращает часть строки
    std::string SubStr(int startPos, int endPos);

    // Возвращает индекс символа
    int GetIndex()
    {
        return indexStr;
    }

    // Метод ищет цифру
    bool FindDigital()
    {
        // Ищем цифру.
        for (int index = indexStr + 1; index < ((int)stringInputUser.length());
             index++) {
            if (!IsWhitespace(index)) {
                if (IsDigitalSymbol(index)) {
                    indexStr = index;
                    return true;
                } else {
                    indexStr = index;
                    return false;
                }
            }
        }

        // Если по неведомым причинам попали сюда, хоть и не должны
        // Тут вообще много вариантов было. решил сделать так.
        return false;
    }

    // Метод ищет число
    int FindNumber()
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

    // Метод преобразования в число из строки
    int StrToInt()
    {
        // Предполагается что переданная сюда строка содержит ТОЛЬКО символы
        // цифр Необходимо провести дополнительную проверку каждого символа на
        // цифру. НО! по скольку поле зарыто от вмешательства пользователя, и в
        // методе получения числа мы явно находили только числа, будем считать
        // ,что строка является корректной. но всё же необходимо ограничить
        // строку по длине цифр. Максимальная длина строки 10 симоволов. По
        // скольку преобразование делаю пока только в тип Int - 2147483647 (11
        // символов) Все символы после будут отсечены. Коряво, но в будущем
        // улучшу

        // Сконвертированное число
        int number = 0;

        // Обрезанная строка
        std::string stringNumberCrop = stringNumber.substr(0, 10);

        int digit = 1;

        // переводим строку в число
        for (int i = stringNumberCrop.length() - 1; i >= 0; i--) {
            number += ((int)stringNumberCrop[i] - 48) * digit;

            digit *= 10;
        }

        return number;
    }
};
