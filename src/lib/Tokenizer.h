#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <array>
#include <cmath>
#include <iostream>
#include <vector>

// Шаблоны не поддерживают раздельную компиляцию.
// Варианты:
// 1. Перенести всю реализацию функции сюда:
//      template <std::size_t SIZE>
//      void Tokenizer(...) {
//          // ...
//      }
// 2. Подключать реализацию препроцессором. Чтобы отличать подключаемые файлы,
//    им можно дать суффикс -inl (от inline).
//       #include <lib/Tokenizer-inl.h>

// enum создает группу глобальных констант.
//
// enum class TokenKind { LeftParen, ... };
// Использование: TokenKind::LeftParen.

enum class TokensKind { LEFTPAREN = 0, RIGHTPAREN, MINUS, COMMA, NUMBER, DOT };

template <std::size_t SIZE>

void Tokenizer(
        const std::array<std::string, SIZE>& tokens,
        std::array<int, 10>& idTokens)
{
    for (int i = 0; i < (int)tokens.size(); i++) {
        if (tokens[i] == "(")
            idTokens[i] = (int)TokensKind::LEFTPAREN;

        if (tokens[i] == ")")
            idTokens[i] = (int)TokensKind::RIGHTPAREN;

        if (tokens[i] == "-")
            idTokens[i] = (int)TokensKind::MINUS;

        if (tokens[i] == ",")
            idTokens[i] = (int)TokensKind::COMMA;

        if (tokens[i] == "number")
            idTokens[i] = (int)TokensKind::NUMBER;

        if (tokens[i] == ".")
            idTokens[i] = (int)TokensKind::DOT;
    }
}

#endif
