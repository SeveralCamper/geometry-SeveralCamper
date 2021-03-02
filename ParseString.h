#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

// Объявляем класс ParseString, в котором будем описывать методы работы со
// строкой
class ParseString : string {
private:
    //Скрыл поле пользовательской строки от изменения вне класса
    // Строка введенная пользователем
    string stringInputUser;

    // В данном случае решаю проблему при которой,
    // если отсутствует нулевой символ, то работа со строкой может возвращать
    // нeкорректный результат
    void AppendZeroSymbol()
    {
        // записываю нулевой символ в конец строки
        stringInputUser.push_back('\0');
    }

public:
    // Хранит индекс строки
    int indexStr = 0;

    // Метод для преобразования букв к нижнему регистру
    string ToLower(string str)
    {
        for (int index = 0; index < str.length(); index++) {
            if ((int)str[index] > 64 && (int)str[index] < 91) {
                str[index] += 32;
            }
        }

        return str;
    }

    // Проверка на символ отличный от буквы
    bool IsNotChar(int index)
    {
        // Если символ отличный от буквы
        if (((int)stringInputUser[index] > 91
             && (int)stringInputUser[index] < 96)
            || (int)stringInputUser[index] < 64
            || (int)stringInputUser[index] > 123)
            return true;

        return false;
    }

    // Метод который ищет первый символ не совпадающий с буквой
    void FindFirstCharDifferentFrom()
    {
        for (int i = 0; i < stringInputUser.length(); i++) {
            // Если получили символ отличный от буквы
            if (IsNotChar(i)) {
                // Запоминаем индекс, на котором остановились
                indexStr = i;

                // И выходим из цикла
                break;
            }
        }
    }

    // Метод возвращающий индекс элемента массива с которым происходит сравнение
    int GetIndexArrayCompare(string array[], int sizeArray)
    {
        int indexKeyWord = -1;

        for (int i = 0; i < sizeArray; i++) {
            if (this->Equals(array[i], stringInputUser.substr(0, indexStr))) {
                indexKeyWord = i;
            }
        }

        return indexKeyWord;
    }

    // Метод сравнения двух строк
    bool Equals(string str_1, string str_2)
    {
        if (ToLower(str_1) == ToLower(str_2))
            return true;
        return false;
    }

    // Метод устанавливающий в поле stringInputUser введную строку пользователя
    void SetString(string str)
    {
        stringInputUser = str;

        // Добавляю в конец строки нулевой символ
        AppendZeroSymbol();
    }

    // Вернуть длину строки
    int Lenght()
    {
        return stringInputUser.length();
    }

    // Возвращает часть строки
    string SubStr(int startPos, int endPos)
    {
        return stringInputUser.substr(startPos, endPos);
    }

    // Возвращает индекс символа
    int GetIndex()
    {
        return indexStr;
    }

    // Если сивол - цифра
    bool IsDigitalSymbol(int index)
    {
        if ((int)stringInputUser[index] > 47
            && (int)stringInputUser[index] < 59)
            return true;
        return false;
    }

    // Проверка на пробел
    // Если пробел - true, если нет то false
    bool IsWhitespace(int index)
    {
        if ((int)stringInputUser[index] == 32)
            return true;
        return false;
    }

    // Открытая скобка или нет
    bool IsOpenParenthesis()
    {
        /// Поскольку следом за ключевым словом
        /// должна следовать открытая круглая скобка,
        /// проверим ее присутствие.
        // Если скобка отсутствует, то укажем на ошибку
        return stringInputUser[indexStr] == '(' ? true : false;
    }

    // Функция проверки введенной открытой скобки
    bool IscloseParenthesis(int index)
    {
        /// Завершаемым символом конструкции должна быть закрытая круглая скобка
        // Если скобка отсутствует, то укажем на ошибку
        return stringInputUser[index] == ')' ? true : false;
    }

    // Метод ищет цифру
    bool FindDigital()
    {
        // Если прошли все прошлые проверки, то теперь
        // ищем первое число затем еще одно число через пробел, и
        // уже потом запятую и снова число.

        // Ищем первую цифру.
        for (int index = indexStr + 1; index < stringInputUser.length();
             index++) {
            if (!IsWhitespace(index)) {
                if (IsDigitalSymbol(index)) {
                    return true;
                } else {
                    indexStr = index;
                    return false;
                }
            }
        }

        return false;
    }
};
