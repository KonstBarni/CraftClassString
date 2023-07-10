#include <iostream>
#include "Functions.h"

char* getStr()
{
    char* inpStr;

    std::cout << "Input the string: ";
    std::cin >> inpStr;
    getline(std::cin, inpStr);

    return inpStr;
}