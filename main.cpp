#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

int main()
{
    int const sizeArray = 1000;

    char *arrayInputString = new char[sizeArray];
    std::cout << "Пожалуйста, введите фигуру и ее координаты в формате: <Название фигуры>(координата Х координата Y, радиус) \n";

    std::fgets(arrayInputString, sizeArray, stdin );
  
    std::cout << arrayInputString;

    for (int i = 0; i < strlen(arrayInputString) - 1; i++)
    {
      if(((int)arrayInputString[i] > 64 && (int)arrayInputString[i] < 91) || ((int)arrayInputString[i] > 96 && (int)arrayInputString[i] < 123 ))
      {
        printf("Yes - %c - %d : ", arrayInputString[i] , (int)arrayInputString[i] );
      }
      else
        printf("No - %c - %d : ", arrayInputString[i] , (int)arrayInputString[i] );
    }
    

    return 0;

}
