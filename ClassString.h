#pragma once
#include <iostream>
using std::ostream;
using std::istream;

class CraftString
{
public:
    CraftString();
    CraftString(char* str);
    CraftString(const CraftString& other);
    CraftString(CraftString&& other);

    CraftString& operator =(const CraftString& other);
    CraftString operator +(const CraftString& other);
    char &operator [](int index);

    int Lengh();
    void print();

    friend ostream & operator<<(ostream & out, const CraftString &str);
    friend istream & operator>>(istream & inp, CraftString & str);

    ~CraftString();
    
private:
    char* str;
    int len;
    static const int CINLIM = 100;

};