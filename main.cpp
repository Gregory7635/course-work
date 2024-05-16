#include <iostream>
#include "ticket.h"

int main() {
    system("color F0");
    setlocale(LC_ALL, "RU");
    std::ifstream inputFile("input.txt");

    if (!inputFile) {
        std::cout << "Ошибка открытия входного файла!" << std::endl;
        return 1;
    }
    Ticket ticket;
    int ticketNumber = 1;

    while (inputFile >> ticket.movieName >> ticket.showTime >> ticket.ticketPrice >> ticket.row >> ticket.seat) {
        ticketsMap[ticketNumber] = ticket;
        ticketNumber++;
    }

    int choice;
    do {
        std::cout << "Выберите действие:\n1. Выбрать билет\n2. Заказать билет\n3. Количество проданных билетов\n4. Сумма проданных билетов\n0. Выход" << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            chooseTicket();
            break;
        case 2:
            int selectedTicketNumber;
            bool isChild;
            std::cout << "Введите номер билета, который вы хотите заказать: ";
            std::cin >> selectedTicketNumber;
            std::cout << "Это детский билет? (1 - да, 0 - нет): ";
            std::cin >> isChild;
            orderTicket(selectedTicketNumber, isChild);
            break;
        case 3:
            numSoldTickets();
            break;
        case 4:
            sumSoldTickets();
            break;
        case 0:
            std::cout << "Завершение программы..." << std::endl;
            break;
        default:
            std::cout << "Выбрано недопустимое действие." << std::endl;
        }
    } while (choice != 0);

    inputFile.close();

    return 0;
}