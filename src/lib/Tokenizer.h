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

template <std::size_t SIZE>
void Tokenizer(const std::array<std::string, SIZE>& tokens,std::array<int, 10>& idTokens);

// #include <lib/Tokenizer-inl.h>

#endif
