#include "ParseString.h"

bool ParseString::IsCloseParenthesis(int index)
{
    /// Завершаемым символом конструкции должна быть закрытая круглая скобка
    // Если скобка отсутствует, то укажем на ошибку
    return stringInputUser[index + 1] == ')';
}
