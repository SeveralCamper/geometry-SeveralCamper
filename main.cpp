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

    cout << "Введите строку с названием фигуры и ее параметрами \n";

    // Считываем строку введенную пользователем с пробелами и переносами
    // строк. Поскольку стандартный метод ввода не позволяет считать
    // строку с пробеламиf
    getline(cin, inputString);

    // Задаю строку
    parseString.SetString(inputString);

    // Получаю некую последовательность буквенных символов до первого вхождения не буквенного симовола
    parseString.FindFirstCharDifferentFrom();

    //
    switch (parseString.GetIndexArrayCompare(
            arrayKeyWords, sizeArrayKeyWords)) {
    case -1: // Ввели что-то неизвестное
        cout << "ошибка \n\n";
        break;

    case 0: // Круг

        // Если скобка открытая
        if (parseString.IsOpenParenthesis()) {
            // проверяем а число ли идет после скобки, и не важно после какого
            // кол-ва пробелов
            if (parseString.FindDigital()) {
                cout << "Digital\n\n";
            } else {
                // Если не число, то указать на номер в строке

                cout << "Error NotDigital\n\n";
                cout << "Символ #" << parseString.indexStr
                     << " должен быть - цифрой \n\n";
            }

        } else {
            // Иначе если скобка закрытая, то пишем ошибку и указываем на номер
            // в строке
            cout << "Символ #" << parseString.indexStr + 1
                 << " должен быть - ( \n\n";
        }

        break;

    case 1: // треугольник
        if (parseString.IsOpenParenthesis()) {
            cout << "Скобка есть\n\n";
        } else {
            cout << "Символ #" << parseString.indexStr + 1
                 << " должен быть - ( \n\n";
        }
        break;

    case 2: // Полигон
        if (parseString.IsOpenParenthesis()) {
            cout << "Скобка есть\n\n";
        } else {
            cout << "Символ #" << parseString.indexStr + 1
                 << " должен быть - ( \n\n";
        }
        break;

    default:
        break;
    }

    return 0;
}