#include "CirclePandS.h"
#include "TrianglePandS.h"
#include "length.h"
#include <array>
#include <cmath>
#include <vector>

#define _USE_MATH_DEFINES

void ShowCoordinatesCircle(const std::vector<int>& coordinates)
{
    std::cout << "\ncircle(" << coordinates[0] << " " << coordinates[1] << ", "
              << coordinates[2] << ")\n";
}

void ShowCoordinatesTriangle(const std::vector<int>& coordinates)
{
    std::cout << "\ntriangle(" << coordinates[0] << " " << coordinates[1]
              << ", " << coordinates[2] << " " << coordinates[3] << ", "
              << coordinates[4] << " " << coordinates[5] << ")\n";
}

enum TokensEnum { TOKEN01 = 101, TOKEN02, TOKEN03, TOKEN04, TOKEN05, TOKEN06 };

template <std::size_t SIZE>

void Tokenizer(
        const std::array<std::string, SIZE>& tokens,
        std::array<int, 10>& idTokens)
{
    for (int i = 0; i < (int)tokens.size(); i++) {
        if (tokens[i] == "(")
            idTokens[i] = TOKEN01;

        if (tokens[i] == ")")
            idTokens[i] = TOKEN02;

        if (tokens[i] == "-")
            idTokens[i] = TOKEN03;

        if (tokens[i] == ",")
            idTokens[i] = TOKEN04;

        if (tokens[i] == "number")
            idTokens[i] = TOKEN05;

        if (tokens[i] == ".")
            idTokens[i] = TOKEN06;
    }
}

int main()
{
    // Массив содержащий координаты фигуры

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

    std::array<int, 10> tokensList = {};

    // введенная пользователем строка
    std::string inputString;

    // Строка для обработки
    ParseString parseString;
    int count;
    std::string keyShow = "";
    std::cout << "Введите количество фигур\n";
    std::cin >> count;
    std::cin.clear();
    fflush(stdin);
    for (int i = 0; i < count + 1; i++) {
        std::vector<int> collectionCoordinates;
        if (i != 0)
            std::cout
                    << "Введите строку с названием фигуры и ее параметрами \n";

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
        if (i != 0) {
            if (!parseString.IsEqualsKeyWord("circle")
                && !parseString.IsEqualsKeyWord("triangle")) {
                isError = true;

                std::cout << "Ошибка в ключевом слове!";
            }
        }

        if (!isError) {
            for (int i = 0; i < (int)tokensList.size(); i++) {
                // Если ошибок не было
                if (!isError) {
                    /// Переходим на Ключ при определенном токене
                    switch (tokensList[i]) {
                    case TOKEN01: // Если токен открытая скобка

                        if (parseString.IsOpenParenthesis()) {
                            isError = false;
                        } else {
                            isError = true;
                            std::cout << "Символ #" << parseString.indexStr + 1
                                      << " должен быть - ( \n\n";
                        }

                        break;

                    case TOKEN02: // Если токен закрытая скобка
                        if (parseString.IsCloseParenthesis()) {
                            isError = false;
                        } else {
                            isError = true;
                            std::cout << "Символ #" << parseString.indexStr + 1
                                      << " должен быть - ) \n\n";
                        }
                        break;

                    case TOKEN04: // Если токен запятая
                        if (parseString.IsComma()) {
                            isError = false;
                        } else {
                            isError = true;
                            std::cout << "Символ #" << parseString.indexStr + 1
                                      << " должен быть - , \n\n";
                        }
                        break;

                    case TOKEN05: // Если токен число

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

            if (keyShow == "circle") {
                ShowCoordinatesCircle(collectionCoordinates);
                CirclePandS(collectionCoordinates);
            }

            if (keyShow == "triangle") {
                ShowCoordinatesTriangle(collectionCoordinates);
                TrianglePandS(collectionCoordinates);
            }
        }
    }

    return 0;
}
