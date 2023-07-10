#include <iostream>
#include "ClassString.h"
//#include "Functions.h"

int main()
{

    CraftString str("sss");
    CraftString str2("pupu");
    CraftString str3;

    std::cin >> str3;
    

    CraftString res;
    res = str + str2 + str3;
    std::cout << str.Lengh() << '\n';
    std::cout << str2.Lengh() << '\n';
    std::cout << res.Lengh() << '\n';
    str[2] = 'H';
    std::cout << str2[2] << '\n';

    res.print();
    str.print();
    return 0;
}