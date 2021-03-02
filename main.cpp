#include <iostream>
#include <stdio.h>
#include <string.h>

#include "ParseString.h"


// Выделяем  пространство std, для более удобной работы с классами и методами

using namespace std;


int main()
{
    // веденная пользователем строка
    string inputString;

    // Строка для обработки
    ParseString parseString;

    // Размерность массива с ключевыми словами
    int sizeArrayKeyWords = 3;

    // Массив с ключевыми словами
    string arrayKeyWords[sizeArrayKeyWords] = {"circle", "triangle", "polygon"};

    // Считываем строку введенную пользователем с пробелами и переносами
    // строк. Поскольку стандартный метод ввода не позволяет считать
    // строку с пробелами
    getline(cin, inputString);

    // Задаю строку
    parseString.SetString(inputString);

    // Добавляю в конец строки нулевой символ
    parseString.AppendZeroSymbol();

    // Ищем ключевое слово
    parseString.FindKeyWord();

    switch (parseString.RetunIndexArrayCompare(
            arrayKeyWords, sizeArrayKeyWords)) {
    case -1: // Ввели что-то неизвестное
        cout << "ошибка";
        break;

    case 0: // Круг

        // Если скобка открытая
        if (parseString.IsOpenParenthesis()) {
            // проверяем а число ли идет после скобки, и не важно после какого
            // числа пробелов Если число
            if (parseString.FindDigital()) {
                cout << "Digital";
            } else {
                // Если не число, то указать на номер в строке

                cout << "Error NotDigital";
                cout << "Символ #" << parseString.indexStr
                     << " должен быть - цифрой \n";
            }

        } else {
            // Иначе если скобка закрытая, то пишем ошибку и указываем на номер
            // в строке
            cout << "Символ #" << parseString.indexStr + 1
                 << " должен быть - ( \n";
        }

        break;

    case 1: // треугольник
        if (parseString.IsOpenParenthesis()) {
            cout << "Скобка есть";
        } else {
            cout << "Символ #" << parseString.indexStr + 1
                 << " должен быть - ( \n";
        }
        break;

    case 2: // Полигон
        if (parseString.IsOpenParenthesis()) {
            cout << "Скобка есть";
        } else {
            cout << "Символ #" << parseString.indexStr + 1
                 << " должен быть - ( \n";
        }
        break;

    default:
        break;
    }

    return 0;
}