#include "ParseString.h"

bool ParseString::IsOpenParenthesis()
{
    /// Поскольку следом за ключевым словом
    /// должна следовать открытая круглая скобка,
    /// проверим ее присутствие.
    // Если скобка отсутствует, то укажем на ошибку
    return stringInputUser[indexStr] == '(';
}
