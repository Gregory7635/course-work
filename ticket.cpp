#include "ticket.h"

std::map<int, Ticket> ticketsMap;
std::set<int> soldTickets;
double totalSales = 0.0;
int totalticket = 0;

void chooseTicket() {
    std::cout << "��������� ������:" << std::endl;
    for (const auto& pair : ticketsMap) {
        if (soldTickets.find(pair.first) == soldTickets.end()) {
            std::cout << "����� #" << pair.first << ": " << pair.second.movieName << " " << " " << "����� ����������: " << pair.second.showTime << " ����:" << pair.second.ticketPrice << " ���" << std::endl;
        }
    }
}

void orderTicket(int ticketNumber, bool isChild) {
    if (soldTickets.find(ticketNumber) == soldTickets.end()) {
        Ticket selectedTicket = ticketsMap[ticketNumber];
        std::ofstream outputFile("purchased_tickets.txt", std::ios::app);
        outputFile << "�����: " << selectedTicket.movieName << std::endl;
        outputFile << "����� ����������: " << selectedTicket.showTime << std::endl;
        outputFile << "���� ������: " << (isChild ? selectedTicket.ticketPrice / 2 : selectedTicket.ticketPrice) <<" ���" << std::endl;
        if (isChild == true) {
            outputFile << "������� �����" << std::endl;
        }
        else {
            outputFile << "�������� �����" << std::endl;
        }
        outputFile << "��� " << selectedTicket.row << ", ����� " << selectedTicket.seat << std::endl;
        outputFile << "-------------------------" << std::endl;
        double ticketPrice = isChild ? selectedTicket.ticketPrice / 2 : selectedTicket.ticketPrice;
        totalSales += ticketPrice;
        totalticket += 1;
        soldTickets.insert(ticketNumber);
        std::cout << "����� ������� ������!" << std::endl;
    }
    else {
        std::cout << "������: ���� ����� ��� ������." << std::endl;
    }
}

void numSoldTickets() {
    std::cout << "����� ������� �������: " << totalticket << std::endl;
}

void sumSoldTickets() {
    std::cout << "����� ����� ������: " << totalSales<< " ���" << std::endl;
}