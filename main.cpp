#include <iostream>
#include "ClassString.h"
#include "Functions.h"
#include "Stack.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    CraftString st = inputStr(); 

    reverse(st);

    return 0;
}