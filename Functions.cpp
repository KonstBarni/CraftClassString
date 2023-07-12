#include <iostream>
#include "Functions.h"
#include "Stack.h"
#include <cstring>

CraftString getStr()
{
    CraftString inpStr;

    std::cout << "Input the string: ";
    std::cin >> inpStr;

    return inpStr;
}

void reverse(CraftString& str)
{
    Stack rev;
    char *s = new char[strlen(str.String())];
    for(int i = 0; i < strlen(str.String()); i++)
    {
        s[i] = str[i];
    }

    char *p = strtok(s, ", ");
    while(p != nullptr)
    {
        std::cout << p << '\n';
        CraftString word(p);
        rev.push(word);
        p = strtok(nullptr, ", ");
    }

    delete[] s;
}