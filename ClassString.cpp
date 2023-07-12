#include <iostream>
#include <cstring>
#include "ClassString.h"

CraftString::CraftString(): len(0), str(nullptr){}

CraftString::CraftString(char* str): len(strlen(str))
{
    this->str = new char[len + 1];
    std::strcpy(this->str, str);
}

CraftString::CraftString(const CraftString& other)
{
    len = strlen(other.str);
    this->str = new char[len + 1];
    std::strcpy(this->str, other.str);
}

CraftString::CraftString(CraftString&& other)
{
    this->len = other.len;
    this->str = other.str;
    other.str = nullptr;
}

CraftString &CraftString::operator =(const CraftString& other)
{
    if (this == &other)
        return *this;

    len = other.len;
    str = new char[len + 1];
    std::strcpy(str, other.str);
    return *this;
}

CraftString &CraftString::operator =(const char * st)
{
    delete[] str;
    len = std::strlen(st);
    str = new char[len + 1];
    std::strcpy(str, st);
    return *this;
}

CraftString CraftString::operator +(const CraftString& other)
{
    char* temp = new char[this->len + other.len +1];
    std::strcpy(temp, this->str);
    std::strcat(temp, other.str);
    CraftString res(temp);
    delete[] temp;
    return res;
}

CraftString CraftString::operator +=(const CraftString& other)
{   
    CraftString temp;
    temp.str = new char [this->len + other.len +1];                    
    // char* temp = new char[this->len + other.len +1];
    std::strcpy(temp.str, this->str);    
    std::strcat(temp.str, other.str);
    // CraftString res(temp);
    // delete[] temp;            
    return temp;
}

CraftString CraftString::operator +=(const char& symb)
{
    CraftString temp;
    temp.len = this->len + 1;
    temp.str = new char[temp.len + 1];
    std::strcpy(temp.str, this->str);
    temp[temp.len-1] = symb;
    temp[temp.len] = '\0';
    delete[] this->str;
    this->str = new char[temp.len];
    this->len = temp.len;
    std::strcpy(this->str, temp.str);
    return *this;
}

char &CraftString::operator[](int index)
{
    if(index < 0 || index >= this->len)
        std::cout <<"шncorrect element index" <<'\n';

    return this->str[index];
}

char* CraftString::getStr()
{
    return str;
}

int CraftString::getLengh()
{
    return len;
}

void CraftString::print()
{
    std::cout << str << std::endl;
}

ostream & operator<<(ostream & out, const CraftString & st)
{
    out << st.str;
    return out;
}

istream & operator>>(istream & inp, CraftString & str)
{
    char temp[CraftString::CINLIM];
    inp.get(temp, CraftString::CINLIM);
    if (inp)
        str = temp;
    while (inp && inp.get() != '\n')
        continue;
    return inp;
}

CraftString::~CraftString()
{
    delete[] str;
}