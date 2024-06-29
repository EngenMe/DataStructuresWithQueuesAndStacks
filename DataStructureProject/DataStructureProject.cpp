#include <iostream>
#include "clsQueueLine.h"

int main()
{
    // Create a queue line for paying bills with prefix "PB0" and waiting time of 10 minutes
    clsQueueLine pay_bills_queue("PB0", 10);

    // Issue five tickets
    pay_bills_queue.IssueTicket();
    pay_bills_queue.IssueTicket();
    pay_bills_queue.IssueTicket();
    pay_bills_queue.IssueTicket();
    pay_bills_queue.IssueTicket();

    // Print information about the queue
    pay_bills_queue.PrintInfo();

    // Print the line of tickets from right to left and left to right
    pay_bills_queue.PrintTicketsLineRTL();
    pay_bills_queue.PrintTicketsLineLTR();

    // Serve the first client in the queue
    pay_bills_queue.ServeClient();

    // Print the line of tickets from right to left and left to right again
    pay_bills_queue.PrintTicketsLineRTL();
    pay_bills_queue.PrintTicketsLineLTR();

    // Print updated information about the queue
    pay_bills_queue.PrintInfo();
    pay_bills_queue.PrintTickets();

    // Serve the next client in the queue
    pay_bills_queue.ServeClient();

    // Print the line of tickets from right to left and left to right again
    pay_bills_queue.PrintTicketsLineRTL();
    pay_bills_queue.PrintTicketsLineLTR();

    // Print updated information about the queue
    pay_bills_queue.PrintInfo();
    pay_bills_queue.PrintTickets();

    return 0;
}
