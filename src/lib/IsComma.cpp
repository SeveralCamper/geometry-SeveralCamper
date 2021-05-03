 #include "ParseString.h"  
   
    bool ParseString::IsComma()
    {
        // Ищем запятую.
        for (int index = indexStr + 1; index < ((int)stringInputUser.length());
             index++) {
            if (!IsWhitespace(index)) {
                if (stringInputUser[index] == ',') {
                    indexStr = index;
                    return true;
                } else {
                    indexStr = index;
                    return false;
                }
            }
        }

        return false;
    }
