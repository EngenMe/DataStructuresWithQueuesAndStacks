#pragma once

template<class T>
class clsDynamicArray
{
protected:
    int _size = 0;  // Variable to keep track of the size of the array
    T* _temp_array;  // Temporary array used for resizing and reversing operations

public:
    T* original_array;  // Pointer to the original array

    // Constructor to initialize the array with a given size
    clsDynamicArray(int size = 0)
    {
        if (size < 0)
            size = 0;

        _size = size;
        original_array = new T[_size];
        _temp_array = new T[_size];
    }

    // Destructor to delete the original array
    ~clsDynamicArray()
    {
        delete[] original_array;
    }

    // Function to set the value at a specific index
    bool SetItem(int index, T value)
    {
        if (index >= _size || index < 0)
            return false;

        original_array[index] = value;
        return true;
    }

    // Function to return the size of the array
    int Size()
    {
        return _size;
    }

    // Function to check if the array is empty
    bool IsEmpty()
    {
        return _size == 0;
    }

    // Function to print the values of the array
    void Print()
    {
        for (int i = 0; i < _size; i++)
        {
            std::cout << original_array[i] << " ";
        }
        std::cout << "\n";
    }

    // Function to resize the array to a new size
    void Resize(int new_size)
    {
        if (new_size == _size)
            return;

        if (new_size == 0)
        {
            _temp_array = new T[0];
            delete[] original_array;
            original_array = _temp_array;
            _size = 0;
            return;
        }

        _temp_array = new T[new_size];

        if (new_size < 0)
            new_size = 0;

        if (new_size < _size)
            _size = new_size;

        for (int i = 0; i < _size; i++)
        {
            _temp_array[i] = original_array[i];
        }

        _size = new_size;

        delete[] original_array;
        original_array = _temp_array;
    }

    // Function to get the value at a specific index
    T GetItem(int index)
    {
        return original_array[index];
    }

    // Function to reverse the array
    void Reverse()
    {
        _temp_array = new T[_size];
        for (int i = 0; i < _size; i++)
        {
            _temp_array[i] = original_array[_size - 1 - i];
        }

        delete[] original_array;
        original_array = _temp_array;
    }

    // Function to clear the array
    void Clear()
    {
        Resize(0);
    }

    // Function to delete the item at a specific index
    bool DeleteItemAt(int index)
    {
        if (index >= _size || index < 0)
            return false;

        _size--;
        _temp_array = new T[_size];

        for (int i = 0; i < index; i++)
        {
            _temp_array[i] = original_array[i];
        }
        for (int i = index + 1; i <= _size; i++)
        {
            _temp_array[i - 1] = original_array[i];
        }

        delete[] original_array;
        original_array = _temp_array;

        return true;
    }

    // Function to delete the first item in the array
    void DeleteFirstItem()
    {
        DeleteItemAt(0);
    }

    // Function to delete the last item in the array
    void DeleteLastItem()
    {
        DeleteItemAt(_size - 1);
    }

    // Function to find the index of a specific value in the array
    int Find(T value)
    {
        for (int i = 0; i < _size; i++)
        {
            if (original_array[i] == value)
                return i;
        }

        return -1;
    }

    // Function to delete a specific value in the array
    bool DeleteItem(T value)
    {
        return DeleteItemAt(Find(value));
    }

    // Function to insert a new item at a specific index
    bool InsertAt(int index, T value)
    {
        if (index > _size || index < 0)
            return false;

        _size++;
        _temp_array = new T[_size];

        for (int i = 0; i < index; i++)
        {
            _temp_array[i] = original_array[i];
        }
        _temp_array[index] = value;
        for (int i = index + 1; i < _size; i++)
        {
            _temp_array[i] = original_array[i - 1];
        }

        delete[] original_array;
        original_array = _temp_array;

        return true;
    }

    // Function to insert a new item at the beginning of the array
    void InsertAtBegining(T value)
    {
        InsertAt(0, value);
    }

    // Function to insert a new item at the end of the array
    void InsertAtEnd(T value)
    {
        InsertAt(_size, value);
    }

    // Function to insert a new item before a specific index
    bool InsertBefore(int index, T value)
    {
        if (index < 0)
            return InsertAt(0, value);
        else
            return InsertAt(index - 1, value);
    }

    // Function to insert a new item after a specific index
    bool InsertAfter(int index, T value)
    {
        if (index > _size)
            InsertAt(_size, value);
        else
            return InsertAt(index + 1, value);
    }
};
