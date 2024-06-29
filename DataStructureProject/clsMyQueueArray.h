#pragma once
#include "clsDynamicArray.h"

template<class T>
class clsMyQueueArray
{
protected:
    clsDynamicArray<T> _my_list;  // Instance of the dynamic array to store queue elements

public:
    // Function to add an element to the back of the queue
    void Push(T value)
    {
        _my_list.InsertAtEnd(value);
    }

    // Function to print the queue elements
    void Print()
    {
        _my_list.Print();
    }

    // Function to get the size of the queue
    int Size()
    {
        return _my_list.Size();
    }

    // Function to get the front element of the queue
    T Front()
    {
        return _my_list.GetItem(0);
    }

    // Function to get the back element of the queue
    T Back()
    {
        return _my_list.GetItem(_my_list.Size() - 1);
    }

    // Function to remove the front element of the queue
    void Pop()
    {
        _my_list.DeleteFirstItem();
    }

    // Function to get the item at a specific index in the queue
    T GetItem(int index)
    {
        return _my_list.GetItem(index);
    }

    // Function to reverse the order of elements in the queue
    void Reverse()
    {
        _my_list.Reverse();
    }

    // Function to update the item at a specific index in the queue
    void UpdateItem(int index, T new_value)
    {
        _my_list.SetItem(index, new_value);
    }

    // Function to insert an item after a specific index in the queue
    void InsertAfter(int index, T value)
    {
        _my_list.InsertAfter(index, value);
    }

    // Function to insert an item at the front of the queue
    void InsertAtFront(T value)
    {
        _my_list.InsertAtBegining(value);
    }

    // Function to insert an item at the back of the queue
    void InsertAtBack(T value)
    {
        Push(value);
    }

    // Function to clear the queue
    void Clear()
    {
        _my_list.Clear();
    }
};
