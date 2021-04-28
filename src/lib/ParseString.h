#include <iostream>
#include <stdio.h>
#include <string.h>

// NOTE:
// Строки можно делать регистронезависимыми через трейты. Пример:
// https://compiler-explorer.com/z/K9G41Pxvn

// Объявляем класс ParseString, в котором будем описывать методы работы со
// строкой
class ParseString final {
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
    // ParseString_ToLower(ParseString* this, std::string str);
    //
    // const:
    // ParseString_ToLower(const ParseString* this, std::string str);
    // std::string ToLower(std::string str) const;

    // Проверка на символ отличный от буквы
    bool IsNotChar(int index)
    {
    	// TODO: https://linux.die.net/man/3/isalpha
        // Если символ отличный от буквы
        return (((int)stringInputUser[index] > 91
             && (int)stringInputUser[index] < 96)
            || (int)stringInputUser[index] < 64
            || (int)stringInputUser[index] > 123);
    }

    // Метод возвращающий истину если ключевое слово совпало
    bool IsEqualsKeyWord(const std::string& keyWord) const
    {
        if (this->Equals(keyWord, stringInputUser.substr(0, indexStr)))
            return true;
        return false;
    }

    // Если сивол - цифра
    bool IsDigitalSymbol(int index)
    {
    	// TODO: https://linux.die.net/man/3/isalpha
    	// TODO: https://csc-software-development.readthedocs.io/ru/2021/code-style.html#if-true-return-true
        if ((int)stringInputUser[index] > 47
            && (int)stringInputUser[index] < 59)
            return true;
        return false;
    }

    // Проверка на пробел
    // Если пробел - true, если нет то false
    bool IsWhitespace(int index)
    {
    	// TODO: https://linux.die.net/man/3/isalpha
        return ((int)stringInputUser[index] == 32);
    }

    // Открытая скобка или нет
    bool IsOpenParenthesis()
    {
        /// Поскольку следом за ключевым словом
        /// должна следовать открытая круглая скобка,
        /// проверим ее присутствие.
        // Если скобка отсутствует, то укажем на ошибку
        return stringInputUser[indexStr] == '(';
    }

    // Функция проверки введенной открытой скобки
    bool IsCloseParenthesis()
    {
        /// Завершаемым символом конструкции должна быть закрытая круглая скобка
        // Если скобка отсутствует, то укажем на ошибку
        return stringInputUser[indexStr + 1] == ')';
    }

    // Метод ищет запятую
    // TODO: is -> Find
    // TODO: std::find_if
    //  https://en.cppreference.com/w/cpp/algorithm/find
    bool IsComma()
    {
        // Ищем запятую.
        for (int index = indexStr + 1; index < ((int)stringInputUser.length());
             index++) {
            if (!IsWhitespace(index)) {
                indexStr = index;            	
                if (stringInputUser[index] == ',') {
                    return true;
                } else {
                    return false;
                }
            }
        }

        return false;
    }

    // Метод который ищет первый символ не совпадающий с буквой
    void FindFirstCharDifferentFrom()
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

    // Метод устанавливающий в поле stringInputUser введную строку пользователя
    void SetString(std::string str);

    // Вернуть длину строки
    int Lenght() const
    {
        return stringInputUser.length();
    }

    // Возвращает часть строки
    std::string SubStr(int startPos, int endPos)
    {
        return stringInputUser.substr(startPos, endPos);
    }

    // Возвращает индекс символа
    int GetIndex()
    {
        return indexStr;
    }

    // Метод ищет цифру
    // TODO: std::find_if
    //  https://en.cppreference.com/w/cpp/algorithm/find
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
    // TODO?: https://en.cppreference.com/w/cpp/string/basic_string/stof
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
