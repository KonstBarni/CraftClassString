#include <iostream>
#include "Stack.h"

bool Stack::isEmpty()
{
    return num_top < 0;
}

bool Stack::isFull()
{
    return num_top >= (MAX - 1);
}

bool Stack::push(CraftString& st)
{
    if(isFull())
    {
        std::cout << "Stack owerflow" << std::endl;
        return false;
    }
    else
    {
        ++num_top;
        *st_items[num_top] = st;
        this->st_top = *st_items[num_top];
        return true;
    }
}

CraftString Stack::pop()
{
    if(isEmpty())
    {
        std::cout << "Stack underflow";
        return 0;
    }
    else
    {
        --num_top;
        this->st_top = *st_items[num_top];
    
        return st_top;
    }
}

CraftString Stack::peek()
{
    if(isEmpty())
    {
        std::cout << "Stack is empty";
        return 0;    
    }
    else
    {
        return st_top;
    }
}

Stack& Stack::operator =(Stack& other)
{
    st_top = other.st_top;
    num_top = other.num_top;
    return *this;
}

Stack::~Stack()
{

}