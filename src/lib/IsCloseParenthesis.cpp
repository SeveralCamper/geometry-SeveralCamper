#include "ParseString.h"

bool ParseString::IsCloseParenthesis()
{
    /// Завершаемым символом конструкции должна быть закрытая круглая скобка
    // Если скобка отсутствует, то укажем на ошибку
    return stringInputUser[indexStr + 1] == ')' ? true : false;
}
