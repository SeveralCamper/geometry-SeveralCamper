#ifndef TOKENIZERH
#define TOKENIZERH

#include <array>
#include <iostream>

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

enum class TokensKind { LEFTPAREN = 10, RIGHTPAREN, MINUS, COMMA, NUMBER, DOT };

template <std::size_t SIZE>

void Tokenizer(
        const std::array<std::string, SIZE>& tokens,
        std::array<TokensKind, 10>& idTokens)
{
    for (int i = 0; i < (int)tokens.size(); i++) {
        if (tokens[i] == "(")
            idTokens[i] = TokensKind::LEFTPAREN;

        if (tokens[i] == ")")
            idTokens[i] = TokensKind::RIGHTPAREN;

        if (tokens[i] == "-")
            idTokens[i] = TokensKind::MINUS;

        if (tokens[i] == ",")
            idTokens[i] = TokensKind::COMMA;

        if (tokens[i] == "number")
            idTokens[i] = TokensKind::NUMBER;

        if (tokens[i] == ".")
            idTokens[i] = TokensKind::DOT;
    }
}

#endif