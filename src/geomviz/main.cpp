#include <array>
#include <cmath>
#include <iostream>
#include <vector>

#include "AreCirclesIntersecting.h"
#include "CirclePandS.h"
#include "CircleShape.h"
#include "ParseString.h"
#include "ShowCoordinatesCircle.h"
#include "ShowCoordinatesTriangle.h"
#include "ShowIntersectShapes.h"
#include "Tokenizer.h"
#include "TrianglePandS.h"
#include "TriangleShape.h"
#include "length.h"

#define _USE_MATH_DEFINES

int main()
{
    int IDShape = 0;

    /// Набор токенов для Круга
    std::array<std::string, 6> tokensCircle
            = {"(", "number", "number", ",", "number", ")"};

    /// Набор токенов для Треугольника
    std::array<std::string, 10> tokensTriangle
            = {"(",
               "number",
               "number",
               ",",
               "number",
               "number",
               ",",
               "number",
               "number",
               ")"};

    std::array<TokensKind, 10> tokensList = {};

    // введенная пользователем строка
    std::string inputString;

    // Строка для обработки
    ParseString parseString;

    std::string keyShow = "";

    std::vector<int> collectionCoordinates;

    std::vector<CircleShape> collectionCircle;
    std::vector<TriangleShape> collectionTriangle;

    std::cout << "Введите строку(и) с названием фигуры и ее параметрами \n";

    do {
        inputString = "";
        parseString.stringInputUser = "";
        tokensList = {};

        // Считываем строку введенную пользователем с пробелами и переносами
        // строк. Поскольку стандартный метод ввода не позволяет считать
        // строку с пробеламиf
        getline(std::cin, inputString);

        // Задаю строку
        parseString.SetString(inputString);

        // Получаю некую последовательность буквенных символов до первого
        // вхождения не буквенного симовола
        parseString.FindFirstCharDifferentFrom();

        // Флаг ошибки
        bool isError = false;
        /// Если ключевое слово - CIRCLE
        if (parseString.IsEqualsKeyWord("circle")) {
            isError = false;

            Tokenizer(tokensCircle, tokensList);

            keyShow = "circle";
        }

        /// Если ключевое слово - TRIANGLE
        if (parseString.IsEqualsKeyWord("triangle")) {
            isError = false;

            Tokenizer(tokensTriangle, tokensList);

            keyShow = "triangle";
        }

        /// Если ключевого слова нет или там ошибка
        if (!parseString.IsEqualsKeyWord("circle")
            && !parseString.IsEqualsKeyWord("triangle")
            && parseString.stringInputUser != "") {
            isError = true;

            std::cout << "Ошибка в ключевом слове!" << std::endl;
        }

        if (!isError && parseString.stringInputUser != "") {
            for (int i = 0; i < (int)tokensList.size(); i++) {
                // Если ошибок не было
                if (!isError) {
                    /// Переходим на Ключ при определенном токене
                    switch (tokensList[i]) {
                    case TokensKind::LEFTPAREN: // Если токен открытая скобка

                        if (parseString.IsOpenParenthesis()) {
                            isError = false;
                        } else {
                            isError = true;
                            std::cout << "Символ #" << parseString.indexStr + 1
                                      << " должен быть - ( \n\n";
                        }

                        break;

                    case TokensKind::RIGHTPAREN: // Если токен закрытая
                                                 // скобка
                        if (parseString.IsCloseParenthesis()) {
                            isError = false;
                        } else {
                            isError = true;
                            std::cout << "Символ #" << parseString.indexStr + 1
                                      << " должен быть - ) \n\n";
                        }
                        break;

                    case TokensKind::COMMA: // Если токен запятая
                        if (parseString.IsComma()) {
                            isError = false;
                        } else {
                            isError = true;
                            std::cout << "Символ #" << parseString.indexStr + 1
                                      << " должен быть - , \n\n";
                        }
                        break;

                    case TokensKind::NUMBER: // Если токен число

                        if (parseString.FindDigital()) {
                            if (parseString.FindNumber() == 0) {
                                isError = false;

                                collectionCoordinates.push_back(
                                        parseString.StrToInt());
                            }

                            if (parseString.FindNumber() == -1) {
                                isError = true;

                                std::cout << "None";
                            }

                            if (parseString.FindNumber() == 1) {
                                isError = true;

                                std::cout << "Символ #" << parseString.indexStr
                                          << " должен быть цифрой или "
                                             "пробелом\n\n";
                            }
                        } else {
                            isError = true;

                            // Если не число, то указать на номер в строке
                            std::cout << "Символ #" << parseString.indexStr
                                      << " должен быть - цифрой \n\n";
                        }

                        break;

                    default:
                        break;
                    }

                } else {
                    break;
                }
            }

            IDShape++;

            if (!isError) {
                if (keyShow == "circle") {
                    CircleShape circle;
                    circle.Set(collectionCoordinates);
                    circle.ID = IDShape;
                    collectionCircle.push_back(circle);
                }

                if (keyShow == "triangle") {
                    TriangleShape triangle;
                    triangle.Set(collectionCoordinates);
                    triangle.ID = IDShape;
                    collectionTriangle.push_back(triangle);
                }
            }

            collectionCoordinates.clear();
        }

    } while (inputString != "");

    std::cout << "+------------------------------+" << std::endl;
    std::cout << "Конец ввода" << std::endl << std::endl;

    for (int i = 0; i < (int)collectionCircle.size(); i++) {
        ShowCoordinatesCircle(collectionCircle[i]);
        CirclePandS(collectionCircle[i]);

        for (int j = 0; j < (int)collectionCircle.size(); j++) {
            if (collectionCircle[i].ID != collectionCircle[j].ID)
                if (AreCirclesIntersecting(
                            collectionCircle[i], collectionCircle[j]))
                    ShowIntersectShapes(
                            collectionCircle[j].ID, collectionCircle[j].key);
        }
    }

    for (int i = 0; i < (int)collectionTriangle.size(); i++) {
        ShowCoordinatesTriangle(collectionTriangle[i]);
        TrianglePandS(collectionTriangle[i]);
    }

    std::cout << std::endl;

    return 0;
}
