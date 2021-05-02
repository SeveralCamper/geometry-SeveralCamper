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

template <std::size_t SIZE>

void Tokenizer(
        const std::array<std::string, SIZE>& tokens,
        std::array<int, 10>& idTokens)
{
    for (int i = 0; i < (int)tokens.size(); i++) {
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

#endif
