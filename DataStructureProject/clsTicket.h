#pragma once
#include <string>
#include "clsDate.h"

class clsTicket
{
private:
    std::string _prefix;  // Prefix for the ticket
    short _order;  // Order number of the ticket
    std::string _date;  // Date the ticket was created

public:
    // Constructor to initialize the ticket with a prefix and order number
    clsTicket(std::string prefix, short order)
    {
        _prefix = prefix;
        _order = order;
        _date = clsDate::GetSystemDateTimeStr();  // Set the date to the current system date and time
    }

    // Function to set the order number of the ticket
    void SetOrder(int order)
    {
        _order = order;
    }

    // Function to get the prefix of the ticket
    std::string GetPrefix()
    {
        return _prefix;
    }

    // Function to get the order number of the ticket
    short GetOrder()
    {
        return _order;
    }

    // Function to get the date the ticket was created
    std::string GetDate()
    {
        return _date;
    }
};
