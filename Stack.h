#pragma once
#include "ClassString.h"

#define MAX 10      //max stack size

class Stack
{
private:

    CraftString st_top;
    int num_top;

public:

    CraftString* st_items[MAX];
    Stack(): st_top(), num_top(-1){}
    bool push(CraftString& st);
    CraftString pop();
    CraftString peek();
    bool isFull();
    bool isEmpty();
    Stack& operator =(Stack& other);
    ~Stack();    
};
