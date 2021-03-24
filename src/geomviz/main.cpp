#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

#include "../libgeomviz/ParseString.h"

// Выделяем  пространство std, для более удобной работы с классами и методами

using namespace std;

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

void Tokenizer(string tokens[], int tokensSize, int idTokens[])
{
    for (int i = 0; i < tokensSize; i++)
    {
        if (tokens[i] == "(")
            idTokens[i] = 101;

        if (tokens[i] == ")")
            idTokens[i] = 102;

        if (tokens[i] == "-")
            idTokens[i] = 103;

        if (tokens[i] == ",")
            idTokens[i] = 104;

        if (tokens[i] == "number")
            idTokens[i] = 105;

        if (tokens[i] == ".")
            idTokens[i] = 106;
    }
}

int main()
{
    // Массив содержащий координаты фигуры
    vector<int> collectionCoordinates;

    /// Набор токенов для Круга
    string tokensCircle[] = {"(", "number", "number", ",", "number", ")"};
    int tokensCircleSize = 6;

    /// Набор токенов для Треугольника
    string tokensTriangle[] = {"(", "number", "number", ",", "number", "number", ",", "number", "number", ")"};
    int tokensTriangleSize = 10;

    int tokensList[] = {};

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
    if (parseString.IsEqualsKeyWord("circle"))
    {
        isError = false;

        Tokenizer(tokensCircle, tokensCircleSize, tokensList);

        tokensListSize = tokensCircleSize;

        keyShow = "circle";
    }

    /// Если ключевое слово - TRIANGLE
    if (parseString.IsEqualsKeyWord("triangle"))
    {
        isError = false;

        Tokenizer(tokensTriangle, tokensTriangleSize, tokensList);

        tokensListSize = tokensTriangleSize;

        keyShow = "triangle";
    }

    /// Если ключевого слова нет или там ошибка
    if (!parseString.IsEqualsKeyWord("circle") && !parseString.IsEqualsKeyWord("triangle"))
    {
        isError = true;

        cout << "Ошибка в ключевом слове!";
    }

    if (!isError)
    {
        for (int i = 0; i < tokensListSize; i++)
        {
            // Если ошибок не было
            if (!isError)
            {
                /// Переходим на Ключ при определенном токене
                switch (tokensList[i])
                {
                case 101: // Если токен открытая скобка

                    if (parseString.IsOpenParenthesis())
                    {
                        isError = false;
                    }
                    else
                    {
                        isError = true;
                        cout << "Символ #" << parseString.indexStr + 1
                             << " должен быть - ( \n\n";
                    }

                    break;

                case 102: // Если токен закрытая скобка
                    if (parseString.IsCloseParenthesis())
                    {
                        isError = false;
                    }
                    else
                    {
                        isError = true;
                        cout << "Символ #" << parseString.indexStr + 1
                             << " должен быть - ) \n\n";
                    }
                    break;

                case 104: // Если токен запятая
                    if (parseString.IsComma())
                    {
                        isError = false;
                    }
                    else
                    {
                        isError = true;
                        cout << "Символ #" << parseString.indexStr + 1
                             << " должен быть - , \n\n";
                    }
                    break;

                case 105: // Если токен число

                    if (parseString.FindDigital())
                    {
                        if (parseString.FindNumber() == 0)
                        {
                            isError = false;

                            collectionCoordinates.push_back(
                                parseString.StrToInt());
                        }

                        if (parseString.FindNumber() == -1)
                        {
                            isError = true;

                            cout << "None";
                        }

                        if (parseString.FindNumber() == 1)
                        {
                            isError = true;

                            cout << "Символ #" << parseString.indexStr
                                 << " должен быть цифрой или пробелом\n\n";
                        }
                    }
                    else
                    {
                        isError = true;

                        // Если не число, то указать на номер в строке
                        cout << "Символ #" << parseString.indexStr
                             << " должен быть - цифрой \n\n";
                    }

                    break;

                default:
                    break;
                }
            }
            else
            {
                break;
            }
        }

        if (keyShow == "circle")
        {
            ShowCoordinatesCircle(collectionCoordinates);
        }

        if (keyShow == "triangle")
        {
            ShowCoordinatesTriangle(collectionCoordinates);
        }
    }

    return 0;
}
