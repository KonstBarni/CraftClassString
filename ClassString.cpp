#include <iostream>
#include <cstring>
#include "ClassString.h"

CraftString::CraftString()
{
    str = nullptr;
    len = 0;
}

CraftString::CraftString(char* str)
{
    len = strlen(str);
    this->str = new char[len + 1];

    for(int i{0}; i < len; i++)
        this->str[i] = str[i];
    
    this->str[len + 1] = '\0';
}

CraftString::CraftString(const CraftString& other)
{
    len = strlen(other.str);
    this->str = new char[len + 1];

    for(int i{0}; i < len; i++)
        this->str[i] = other.str[i];
    
    this->str[len + 1] = '\0';
}

CraftString::CraftString(CraftString&& other)
{
    this->len = other.len;
    this->str = other.str;
    other.str = nullptr;
}

CraftString &CraftString::operator =(const CraftString& other)
{
    if(this->str != nullptr)
        delete[] str;

    len = strlen(other.str);
    this->str = new char[len + 1];

    for(int i{0}; i < len; i++)
        this->str[i] = other.str[i];
    
    this->str[len + 1] = '\0';

    return *this;
}

CraftString CraftString::operator +(const CraftString& other)
{
    CraftString plusStr;

    plusStr.str = new char[strlen(this->str) + strlen(other.str) +1];

    int i = 0;
    for(;i < strlen(this->str); i++)
        plusStr.str[i] = this->str[i];

    for(int j = 0; j < strlen(other.str); j++, i++)
        plusStr.str[i] = other.str[j];

    plusStr.str[i+1] = '\0';

    plusStr.len = strlen(this->str) + strlen(other.str);
    return plusStr;
}

char &CraftString::operator[](int index)
{
    return this->str[index];
}

int CraftString::Lengh()
{
    return len;
}

void CraftString::print()
{
    std::cout << str << std::endl;
}

CraftString::~CraftString()
{
    delete[] str;
}