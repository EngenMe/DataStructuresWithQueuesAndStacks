#pragma once
#include "clsMyQueue.h"

template<class T>
class clsMyStack : public clsMyQueue<T>
{
public:
    // Function to push an element onto the top of the stack
    void Push(T value)
    {
        clsMyQueue<T>::_my_list.InsertAtBegining(value);
    }

    // Function to get the top element of the stack
    T Top()
    {
        return clsMyQueue<T>::Front();
    }

    // Function to get the bottom element of the stack
    T Bottom()
    {
        return clsMyQueue<T>::Back();
    }

    // Function to insert an element at the top of the stack
    void InsertAtTop(T value)
    {
        Push(value);
    }

    // Function to insert an element at the bottom of the stack
    void InsertAtBottom(T value)
    {
        clsMyQueue<T>::_my_list.InsertAtEnd(value);
    }
};
