#include <iostream>
#include "Functions.h"
#include "Stack.h"
#include <cstring>

CraftString inputStr()
{
    CraftString inpStr;

    std::cout << "Введите слова через пробел: ";
    std::cin >> inpStr;

    return inpStr;
}

void reverse(CraftString& str)
{
    //Stack rev;

    char* sp[10];
    int i = 0, count = 0;

    char *p = strtok(str.getStr(), ", ");

    while(p != nullptr)
    {
        sp[i] = p;
        i++;
        count++;
        //CraftString word(p);
        //rev.push(word);               //ошибка пямяти
        p = strtok(nullptr, ", ");
    }

    std::cout << "Реверсивный порядок слов: ";

    while(count-- != 0)
    {
        if(count)
        {
            std::cout << sp[count] << " ";
        }
        else
        {
            std::cout << sp[count] << std::endl;
        }
    }
}