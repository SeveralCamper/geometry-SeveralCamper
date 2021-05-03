#include <iostream>
#include <stdio.h>
#include <string.h>

// Объявляем класс ParseString, в котором будем описывать методы работы со
// строкой
class ParseString {
private:
    //Скрыл поле пользовательской строки от изменения вне класса
    // Строка введенная пользователем

    std::string stringInputUser;

    //Строка хранящая число
    std::string stringNumber;

public:
    // Хранит индекс строки
    int indexStr = 0;

    // Метод для преобразования букв к нижнему регистру
    std::string ToLower(std::string str);

    // Проверка на символ отличный от буквы
    bool IsNotChar(int index);

    // Метод возвращающий истину если ключевое слово совпало
    bool IsEqualsKeyWord(std::string keyWord);

    // Если сивол - цифра
    bool IsDigitalSymbol(int index);

    // Проверка на пробел
    // Если пробел - true, если нет то false
    bool IsWhitespace(int index);

    // Открытая скобка или нет
    bool IsOpenParenthesis();

    // Функция проверки введенной открытой скобки
    bool IsCloseParenthesis();

    // Метод ищет запятую
    bool IsComma();

    // Метод который ищет первый символ не совпадающий с буквой
    void FindFirstCharDifferentFrom();

    // Метод сравнения двух строк
    // В данном случае не просто сравнивает ,
    // а еще преобразует к единому регистру
    bool Equals(std::string str_1, std::string str_2);

    // Метод устанавливающий в поле stringInputUser введную строку пользователя
    void SetString(std::string str);

    // Вернуть длину строки
    int Lenght();

    // Возвращает часть строки
    std::string SubStr(int startPos, int endPos);

    // Возвращает индекс символа
    int GetIndex();

    // Метод ищет цифру
    bool FindDigital();

    // Метод ищет число
    int FindNumber();

    // Метод преобразования в число из строки
    int StrToInt();
};
