#include <iostream>
#include "ClassString.h"
#include "Functions.h"

int main()
{
    char* instr = getStr();
    
    CraftString str(instr);
    CraftString str2("pupu");
    

    CraftString res;
    res = str + str2;
    std::cout << str.Lengh() << '\n';
    std::cout << str2.Lengh() << '\n';
    std::cout << res.Lengh() << '\n';
    str[2] = 'H';
    std::cout << str2[2] << '\n';

    res.print();
    str.print();
    return 0;
}