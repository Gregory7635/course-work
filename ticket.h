#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

struct Ticket {
    std::string movieName;
    std::string showTime;
    double ticketPrice;
    int row;
    int seat;
};

extern std::map<int, Ticket> ticketsMap;
extern std::set<int> soldTickets;
extern double totalSales;
extern int totalticket;

void chooseTicket();
void orderTicket(int ticketNumber, bool isChild);
void numSoldTickets();
void sumSoldTickets();
