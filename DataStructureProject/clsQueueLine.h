#pragma once
#include <queue>
#include "clsTicket.h"

class clsQueueLine : public clsTicket
{
private:
    std::queue<clsTicket> _queue;  // Queue to store the tickets
    std::string _prefix;  // Prefix for the tickets
    short _waiting_time;  // Average waiting time per client
    short _total_tickets = 0;  // Total number of tickets issued
    short _served_clients = 0;  // Number of clients served
    short _waiting_clients = 0;  // Number of clients waiting
    short _order;  // Order number for tickets

public:
    // Constructor to initialize the queue line with prefix, waiting time, and starting order
    clsQueueLine(std::string prefix, short waiting_time, short order = 0) : clsTicket(prefix, order)
    {
        _order = order;
        _prefix = prefix;
        _waiting_time = waiting_time;
    }

    // Function to issue a new ticket
    void IssueTicket()
    {
        _queue.push(clsQueueLine(_prefix, _waiting_time, ++_order));
        _total_tickets++;
        _waiting_clients++;
    }

    // Function to print information about the queue
    void PrintInfo()
    {
        std::cout << "---------------------------------------\n";
        std::cout << "           *** Queue Info ***\n";
        std::cout << "---------------------------------------\n";

        std::cout << "Prefix          : " << _prefix << "\n";
        std::cout << "Total Tickets   : " << _total_tickets << "\n";
        std::cout << "Served Clients  : " << _served_clients << "\n";
        std::cout << "Waiting Clients : " << _waiting_clients << "\n";

        std::cout << "---------------------------------------\n";
    }

    // Function to print the line of tickets from right to left
    void PrintTicketsLineRTL()
    {
        if (_queue.empty())
        {
            std::cout << "No tickets to show!\n";
            return;
        }

        std::cout << "Tickets: ";
        std::queue<clsTicket> temp_q = _queue;
        while (true)
        {
            std::cout << _prefix << temp_q.front().GetOrder();
            temp_q.pop();
            if (temp_q.empty())
                break;

            std::cout << " <-- ";
        }
        std::cout << "\n";
    }

    // Function to print the line of tickets from left to right
    void PrintTicketsLineLTR()
    {
        if (_queue.empty())
        {
            std::cout << "No tickets to show!\n";
            return;
        }

        std::cout << "Tickets: ";
        std::queue<clsTicket> temp_q = _queue;
        while (true)
        {
            std::cout << _prefix << temp_q.back().GetOrder() - temp_q.front().GetOrder() + 1;
            temp_q.pop();
            if (temp_q.empty())
                break;

            std::cout << " --> ";
        }
        std::cout << "\n";
    }

    // Function to print a single ticket
    void PrintOneTicket(clsTicket ticket)
    {
        std::cout << "---------------------------------------\n";

        std::cout << "                " << ticket.GetPrefix() << ticket.GetOrder() << "\n";
        std::cout << "         " << ticket.GetDate() << "\n";
        std::cout << "          Waiting Clients: " << ticket.GetOrder() - 1 - _served_clients << "\n";
        std::cout << "            Serve Time In\n";
        std::cout << "             " << _waiting_time * (ticket.GetOrder() - 1 - _served_clients) <<
            " Minutes\n";

        std::cout << "---------------------------------------\n";
    }

    // Function to print all tickets in the queue
    void PrintTickets()
    {
        if (_queue.empty())
        {
            std::cout << "No tickets to show!\n";
            return;
        }

        std::queue<clsTicket> temp_q = _queue;

        while (!temp_q.empty())
        {
            PrintOneTicket(temp_q.front());
            temp_q.pop();
        }
    }

    // Function to serve a client (remove the front ticket from the queue)
    void ServeClient()
    {
        _queue.pop();
        _served_clients++;
        _waiting_clients--;
    }
};
