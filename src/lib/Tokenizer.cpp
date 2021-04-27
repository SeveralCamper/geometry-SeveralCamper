#include "Tokenizer.h"

enum TokensEnum { TOKEN01 = 101, TOKEN02, TOKEN03, TOKEN04, TOKEN05, TOKEN06 };

template <std::size_t SIZE>

void Tokenizer(const std::array<std::string, SIZE>& tokens,std::array<int, 10>& idTokens)
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
