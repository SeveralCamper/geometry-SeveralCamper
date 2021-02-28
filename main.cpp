#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string.h>

using namespace std;

class UserString : string
{
private:
   // Строка введенная пользователем
   string self;

public:
   // Метод для преобразования букв к нижнему регистру
   string ToLower(string str)
   {
      for (int index = 0; index < str.length(); index++)
      {
         if ((int)str[index] > 64 && (int)str[index] < 91)
         {
            str[index] += 32;
         }
      }
      return str;
   }

   bool Equals(string str_1, string str_2)
   {
      if (ToLower(str_1) == ToLower(str_2))
         return true;
      return false;
   }

   // В данном случае решаю проблему при которой,
   // если отсутствует нулевой символ, то работа со строкой может возвращать нкорректный результат
   string Str(string str)
   {
      self = str;

      // записываю нулевой символ в конец строки
      self.push_back('\0');

      return self;
   }

   // Вернуть длину строки
   int Lenght()
   {
      return self.length();
   }

};

int main()
{
   // веденная пользователем строка
   string inputString;

   // Строка для обработки
   UserString userString;

   // Размерность массива с ключевыми словами
   int sizeArrayKeyWords = 3;

   // Массив с ключевыми словами
   string arrayKeyWords[sizeArrayKeyWords] = {"circle", "triangle", "polygon"};

   // Хранит индекс строки
   int indexStr = 0;

   // Считываем строку введенную пользователем с пробелами и переносами строк.
   // Поскольку стандартный метод ввода не позволяет считать строку с пробелами
   getline(cin, inputString);

   // Полученную строку помещаю в пользоватльский тип для работы со строками
   userString.Str(inputString);

   return 0;
}