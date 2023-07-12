#pragma once
#include "ClassString.h"

#define MAX 5

class Stack
{
private:

    CraftString st_top;
    int num_top;

public:
    CraftString* st_items[MAX];
    
    Stack(): num_top(-1), st_top(){}
    bool push(CraftString& st);
    CraftString pop();
    CraftString peek();
    bool isFull();
    bool isEmpty();
    Stack& operator =(Stack& other);
    //~Stack();
    
};
