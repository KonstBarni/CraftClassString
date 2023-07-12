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

// CraftString::CraftString(int size, const CraftString& other)
// {
//     len = size;
//     this->str = new char[len + 1];
//     std::strncpy(this->str, other.str, size);
//     this->str[len + 1] = '\0';
// }

CraftString::CraftString(const CraftString& other)
{
    len = other.len;
    this->str = other.str;
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
    this->str = other.str;
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
    CraftString plusStr;
    delete[] plusStr.str;

    plusStr.len = this->len + other.len;
    plusStr.str = new char[this->len + other.len +1];

    std::strcpy(plusStr.str, this->str);
    std::strcpy(plusStr.str + this->len, other.str);
    return plusStr;
}

CraftString CraftString::operator +=(const CraftString& other)
{
    CraftString temp;                        
 
    temp.len = strlen(this->str) + other.len;    
    temp.str = new char[temp.len + 1];            
    
    std::strcpy(temp.str, std::strcat(this->str, other.str));

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
    return this->str[index];
}

char* CraftString::String()
{
    return str;
}

int CraftString::Lengh()
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