#include "ticket.h"

std::map<int, Ticket> ticketsMap;
std::set<int> soldTickets;
double totalSales = 0.0;
int totalticket = 0;

void chooseTicket() {
    std::cout << "Доступные билеты:" << std::endl;
    for (const auto& pair : ticketsMap) {
        if (soldTickets.find(pair.first) == soldTickets.end()) {
            std::cout << "Билет #" << pair.first << ": " << pair.second.movieName << " " << " " << "Время киносеанса: " << pair.second.showTime << " Цена:" << pair.second.ticketPrice << " Руб" << std::endl;
        }
    }
}

void orderTicket(int ticketNumber, bool isChild) {
    if (soldTickets.find(ticketNumber) == soldTickets.end()) {
        Ticket selectedTicket = ticketsMap[ticketNumber];
        std::ofstream outputFile("purchased_tickets.txt", std::ios::app);
        outputFile << "Фильм: " << selectedTicket.movieName << std::endl;
        outputFile << "Время киносеанса: " << selectedTicket.showTime << std::endl;
        outputFile << "Цена билета: " << (isChild ? selectedTicket.ticketPrice / 2 : selectedTicket.ticketPrice) <<" Руб" << std::endl;
        if (isChild == true) {
            outputFile << "Детский билет" << std::endl;
        }
        else {
            outputFile << "Взрослый билет" << std::endl;
        }
        outputFile << "Ряд " << selectedTicket.row << ", Место " << selectedTicket.seat << std::endl;
        outputFile << "-------------------------" << std::endl;
        double ticketPrice = isChild ? selectedTicket.ticketPrice / 2 : selectedTicket.ticketPrice;
        totalSales += ticketPrice;
        totalticket += 1;
        soldTickets.insert(ticketNumber);
        std::cout << "Билет успешно куплен!" << std::endl;
    }
    else {
        std::cout << "Ошибка: Этот билет уже продан." << std::endl;
    }
}

void numSoldTickets() {
    std::cout << "Всего продано билетов: " << totalticket << std::endl;
}

void sumSoldTickets() {
    std::cout << "Общая сумма продаж: " << totalSales<< " Руб" << std::endl;
}