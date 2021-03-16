#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "ParseString.h"

// Выделяем  пространство std, для более удобной работы с классами и методами

using namespace std;

// Перечисления токенов
enum Tokens {
    NUMBER = 1,            // Число
    CLOSE_PARENTHESIS = 2, // Закрытая скобка
    OPEN_PARENTHESIS = 3,  // Открытая скобка
    COMMA = 4              // Запятая
};

void ShowCoordinatesCircle(vector<int> coordinates)
{
    cout << "\ncircle(" << coordinates[0] << " " << coordinates[1] << ", "
         << coordinates[2] << ")\n";
}

void ShowCoordinatesTriangle(vector<int> coordinates)
{
    cout << "\ntriangle(" << coordinates[0] << " " << coordinates[1] << ", "
         << coordinates[2] << " " << coordinates[3] << ", " << coordinates[4]
         << " " << coordinates[5] << ")\n";
}

int main()
{
    // Массив содержащий координаты фигуры
    vector<int> collectionCoordinates;

    /// Набор токенов для Круга
    Tokens tokensCircle[] = {
            OPEN_PARENTHESIS, NUMBER, NUMBER, COMMA, NUMBER, CLOSE_PARENTHESIS};

    /// Набор токенов для Треугольника
    Tokens tokensTriangle[]
            = {OPEN_PARENTHESIS,
               NUMBER,
               NUMBER,
               COMMA,
               NUMBER,
               NUMBER,
               COMMA,
               NUMBER,
               NUMBER,
               CLOSE_PARENTHESIS};

    Tokens tokensList[20];

    int tokensListSize = 0;

    // введенная пользователем строка
    string inputString;

    // Строка для обработки
    ParseString parseString;

    string keyShow = "";

    cout << "Введите строку с названием фигуры и ее параметрами \n";

    // Считываем строку введенную пользователем с пробелами и переносами
    // строк. Поскольку стандартный метод ввода не позволяет считать
    // строку с пробеламиf
    getline(cin, inputString);

    // Задаю строку
    parseString.SetString(inputString);

    // Получаю некую последовательность буквенных символов до первого вхождения
    // не буквенного симовола
    parseString.FindFirstCharDifferentFrom();

    // Флаг ошибки
    bool isError = false;

    /// Если ключевое слово - CIRCLE
    if (parseString.IsEqualsKeyWord("circle")) {
        isError = false;

        tokensListSize = 6;

        for (int i = 0; i < tokensListSize; i++) {
            tokensList[i] = tokensCircle[i];
        }

        keyShow = "circle";
    }

    /// Если ключевое слово - TRIANGLE
    if (parseString.IsEqualsKeyWord("triangle")) {
        isError = false;

        tokensListSize = 10;

        for (int i = 0; i < tokensListSize; i++) {
            tokensList[i] = tokensTriangle[i];
        }

        keyShow = "triangle";
    }

    /// Если ключевого слова нет или там ошибка
    if (!parseString.IsEqualsKeyWord("circle")
        && !parseString.IsEqualsKeyWord("triangle")) {
        isError = true;

        cout << "Ошибка в ключевом слове!";
    }

    if (!isError) {
        for (int i = 0; i < tokensListSize; i++) {
            // Если ошибок не было
            if (!isError) {
                /// Переходим на Ключ при определенном токене
                switch (tokensList[i]) {
                case 1: // Если токен число

                    if (parseString.FindDigital()) {
                        if (parseString.FindNumber() == 0) {
                            isError = false;

                            collectionCoordinates.push_back(
                                    parseString.StrToInt());
                        }

                        if (parseString.FindNumber() == -1) {
                            isError = true;

                            cout << "None";
                        }

                        if (parseString.FindNumber() == 1) {
                            isError = true;

                            cout << "Символ #" << parseString.indexStr
                                 << " должен быть цифрой или пробелом\n\n";
                        }
                    } else {
                        isError = true;

                        // Если не число, то указать на номер в строке
                        cout << "Символ #" << parseString.indexStr
                             << " должен быть - цифрой \n\n";
                    }

                    break;

                case 2: // Если токен закрытая скобка
                    if (parseString.IsCloseParenthesis()) {
                        isError = false;
                    } else {
                        isError = true;
                        cout << "Символ #" << parseString.indexStr + 1
                             << " должен быть - ) \n\n";
                    }
                    break;

                case 3: // Если токен открытая скобка

                    if (parseString.IsOpenParenthesis()) {
                        isError = false;
                    } else {
                        isError = true;
                        cout << "Символ #" << parseString.indexStr + 1
                             << " должен быть - ( \n\n";
                    }

                    break;
                case 4: // Если токен запятая
                    if (parseString.IsComma()) {
                        isError = false;
                    } else {
                        isError = true;
                        cout << "Символ #" << parseString.indexStr + 1
                             << " должен быть - , \n\n";
                    }
                    break;

                default:
                    break;
                }
            } else {
                break;
            }
        }
    }

    if (keyShow == "circle") {
        ShowCoordinatesCircle(collectionCoordinates);
    }

    if (keyShow == "triangle") {
        ShowCoordinatesTriangle(collectionCoordinates);
    }

    return 0;
}
