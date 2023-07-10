#pragma once

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

    ~CraftString();
    
private:
    char* str;
    int len;

};