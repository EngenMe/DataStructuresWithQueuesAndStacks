#pragma once
#include <string>
#include <stack>

class clsMyString
{
private:
    std::stack<std::string> _undo;  // Stack to store the undo history
    std::stack<std::string> _redo;  // Stack to store the redo history
    std::string _value;  // Current value of the string

public:
    // Function to set the value of the string and store the previous value in the undo stack
    void SetValue(std::string value)
    {
        _undo.push(_value);
        _value = value;
    }

    // Function to get the current value of the string
    std::string GetValue()
    {
        return _value;
    }

    // Property to get and set the value using the SetValue and GetValue functions
    __declspec(property(get = GetValue, put = SetValue)) std::string value;

    // Function to undo the last change, moving the current value to the redo stack
    void Undo()
    {
        if (_undo.empty())
            return;

        _redo.push(_value);
        _value = _undo.top();
        _undo.pop();
    }

    // Function to redo the last undone change, moving the current value to the undo stack
    void Redo()
    {
        if (_redo.empty())
            return;

        _undo.push(_value);
        _value = _redo.top();
        _redo.pop();
    }
};
