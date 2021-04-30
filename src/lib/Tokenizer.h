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

#endif
