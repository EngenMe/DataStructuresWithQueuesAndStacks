#pragma once
#include "clsMyQueue.h"

template<class T>
class clsMyStack : public clsMyQueue<T>
{
public:
    // Function to push an element onto the top of the stack
    void Push(T value)
    {
        // Insert the new element at the beginning of the underlying list
        clsMyQueue<T>::_my_list.InsertAtBegining(value);
    }

    // Function to get the top element of the stack
    T Top()
    {
        // Return the front element of the underlying list (top of the stack)
        return clsMyQueue<T>::Front();
    }

    // Function to get the bottom element of the stack
    T Bottom()
    {
        // Return the back element of the underlying list (bottom of the stack)
        return clsMyQueue<T>::Back();
    }

    // Function to insert an element at the top of the stack
    void InsertAtTop(T value)
    {
        // Use the Push function to insert at the top of the stack
        Push(value);
    }

    // Function to insert an element at the bottom of the stack
    void InsertAtBottom(T value)
    {
        // Insert the new element at the end of the underlying list
        clsMyQueue<T>::_my_list.InsertAtEnd(value);
    }
};
