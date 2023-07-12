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
    CraftString& operator =(const char * st);
    CraftString operator +(const CraftString& other);
    CraftString operator +=(const CraftString& other);
    CraftString operator +=(const char& symb);
    char &operator [](int index);

    char* getStr();
    int getLengh();
    void print();

    friend ostream & operator<<(ostream & out, const CraftString &str);
    friend istream & operator>>(istream & inp, CraftString & str);

    ~CraftString();
    
private:
    
    int len;
    char* str;
    static const int CINLIM = 100;

};