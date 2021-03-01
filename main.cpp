#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class UserString : string {
private:
    // Строка введенная пользователем
    string self;

public:
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

    // Метод сравнения двух строк
    bool Equals(string str_1, string str_2)
    {
        if (ToLower(str_1) == ToLower(str_2))
            return true;
        return false;
    }

    // В данном случае решаю проблему при которой,
    // если отсутствует нулевой символ, то работа со строкой может возвращать
    // нкорректный результат
    string AppendZeroSymbol(string str)
    {
        self = str;

        // записываю нулевой символ в конец строки
        self.push_back('\0');

        return self;
    }

    // Вернуть длину строки
    int Lenght()
    {
        return self.length();
    }

    // Возвращает часть строки
    string SubStr(int startPos, int endPos)
    {
        return self.substr(startPos, endPos);
    }

    // Метод возвращающий индекс элемента массива с которым происходит сравнение
    int RetunIndexArrayCompare(string array[], int sizeArray, string str)
    {
        int index = -1;

        for (int i = 0; i < sizeArray; i++) {
            if (this->Equals(array[i], str)) {
                index = i;
            }
        }

        return index;
    }

    // Проверка на символ отличный от буквы
    bool IsNotLetter(int index)
    {
        // Если символ отличный от буквы
        if (((int)self[index] > 91 && (int)self[index] < 96)
            || (int)self[index] < 64 || (int)self[index] > 123)
            return true;

        return false;
    }

    // Проверка на пробел
    // Если пробел - true, если нет то false
    bool IsSpaceSymbol(int index)
    {
        if ((int)self[index] == 32)
            return true;
        return false;
    }

    // Функция проверки введенной открытой скобки
    bool IsOpenParenthesis(int index)
    {
        /// Поскольку следом за ключевым словом
        /// должна следовать открытая круглая скобка,
        /// проверим ее присутствие.
        // Если скобка отсутствует, то укажем на ошибку
        return self[index] == '(' ? true : false;
    }

    // Функция проверки введенной открытой скобки
    bool IscloseParenthesis(int index)
    {
        /// Завершаемым символом конструкции должна быть закрытая круглая скобка
        // Если скобка отсутствует, то укажем на ошибку
        return self[index] == ')'? true : false;
    }

    // Метод для работы с Кругом
    // Я уже не знаю как это правильно назвать....
    // как эта хрень может называться...
    /// Проверка нотификации? или что-то типа того
    // проверка синтаксиса. я короче уже ХЗ. Сам придумай )))))))))
    void NonameFunctionForWorkCircle(UserString str, int indexStr)
    {
        // Если прошли все прошлые проверки, то теперь
        // ищем первое число затем еще одно число через пробел, и
        // уже потом запятую и снова число.

        // Ищем первую цифру.
        for (int i = indexStr; i < str.Lenght(); i++) {
            // if () {
            // }
        }
    };
};

int main()
{
    // веденная пользователем строка
    string inputString;

    // Строка для обработки
    UserString userString;

    // Размерность массива с ключевыми словами
    int sizeArrayKeyWords = 3;

    // Массив с ключевыми словами
    string arrayKeyWords[sizeArrayKeyWords] = {"circle", "triangle", "polygon"};

    // Хранит индекс строки
    int indexStr = 0;

    // Считываем строку введенную пользователем с пробелами и переносами строк.
    // Поскольку стандартный метод ввода не позволяет считать строку с пробелами
    getline(cin, inputString);

    // Добавляю в конец строки нулевой символ
    userString.AppendZeroSymbol(inputString);

    /// По своеобразной логике было решено, проверить сначала ключевое слово
    /// В данном случае circle || triangle || polygon
    /// Для этого будем считать, что любой символ кроме заглавных и строчных
    /// литералов будет являться ограничителем для проверки введеного ключевого
    /// слова
    for (int i = 0; i < userString.Lenght(); i++) {
        // Если получили символ отличный от буквы
        if (userString.IsNotLetter(i)) {
            // Запоминаем индекс, на котором остановились
            indexStr = i;

            // И выходим из цикла
            break;
        }
    }

    switch (userString.RetunIndexArrayCompare(
            arrayKeyWords, sizeArrayKeyWords, userString.SubStr(0, indexStr))) {
    case -1: // Ввели что-то неизвестное
        cout << "ошибка";
        break;

    case 0: // Круг

        if (userString.IsOpenParenthesis(indexStr)) {
            userString.NonameFunctionForWorkCircle(userString, 0);
        } else {
            cout << "Символ #" << indexStr + 1 << " должен быть - ( \n";
        }

        break;

    case 1: // треугольник
        if (userString.IsOpenParenthesis(indexStr)) {
            cout << "Скобка есть";
        } else {
            cout << "Символ #" << indexStr + 1 << " должен быть - ( \n";
        }
        break;

    case 2: // Полигон
        if (userString.IsOpenParenthesis(indexStr)) {
            cout << "Скобка есть";
        } else {
            cout << "Символ #" << indexStr + 1 << " должен быть - ( \n";
        }
        break;

    default:
        break;
    }

    return 0;
}