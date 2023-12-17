#include "UserInterface.h"

UserInterface::UserInterface() {
    ptrProductionList = new ProductionList;
    ptrProductionList->loadFromFile("production_data.txt");
    ptrSalesList = new SalesList;
    ptrExpensesList = new ExpensesList;
}

UserInterface::~UserInterface() {
    delete ptrSalesList;
    delete ptrExpensesList;
}

void UserInterface::choosePosition() {
    system("cls");
    std::cout << "�������� ���� ���������:\n1. ������\n2. ���������\n3. ��������\n��� ������ ������� q\n�������� ����� ����: ";
    std::cin >> choice;
    switch (choice) {
    case '1':
        interactWithCashier();
        break;
    case '2':
        interactWithAccountant();
        break;
    case '3':
        interactWithManager();
        break;
    case 'q':
        return;
    default:
        std::cout << "����������� �����";
        break;
    }
}

void UserInterface::interactWithCashier() {
    while (true) {
        system("cls");
        std::cout << "1. ������ ����� �������\n��� ������ ������� q\n�������� ����� ����: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            ptrSaleInputScreen = new SaleInputScreen(ptrSalesList, ptrProductionList);
            while (choice != 'n') {
                system("cls");
                ptrSaleInputScreen->setSale();
                std::cout << "������� ������ ��� ���� �������? y|n ";
                std::cin >> choice;
            }
            delete ptrSaleInputScreen;
            break;
        case 'q':
            choosePosition();
            return;
        default:
            std::cout << "����������� �����";
            break;
        }
    }
}

void UserInterface::interactWithAccountant() {
    while (true) {
        system("cls");
        std::cout << "1. ������� ������� �������\n2. ������� ������� ��������\n3. ������� ������� �����\n4. ������ �����\n5. ������ ������� ����������\n��� ������ ������� q\n�������� ����� ����: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            system("cls");
            ptrSalesList->displayTable();
            std::cout << "\n����� ��������� � ���� ������� ����� ������� ";
            system("pause > nul");
            break;
        case '2':
            system("cls");
            ptrExpensesList->displayTable();
            std::cout << "\n����� ��������� � ���� ������� ����� ������� ";
            system("pause > nul");
            break;
        case '3':
            ptrAnnualReport = new AnnualReport(ptrSalesList, ptrExpensesList);
            ptrAnnualReport->display();
            delete ptrAnnualReport;
            std::cout << "\n����� ��������� � ���� ������� ����� ������� ";
            system("pause > nul");
            break;
        case '4':
            ptrExpenseInputScreen = new ExpenseInputScreen(ptrExpensesList);
            while (choice != 'n') {
                system("cls");
                ptrExpenseInputScreen->setExpense('t');
                std::cout << "������� ������ ��� ���� �����? y|n ";
                std::cin >> choice;
            }
            delete ptrExpenseInputScreen;
            break;
        case '5':
            ptrExpenseInputScreen = new ExpenseInputScreen(ptrExpensesList);
            while (choice != 'n') {
                system("cls");
                ptrExpenseInputScreen->setExpense('s');
                std::cout << "������� ������ ��� ���� �������? y|n ";
                std::cin >> choice;
            }
            delete ptrExpenseInputScreen;
            break;
        case 'q':
            choosePosition();
            return;
        }
    }
}

void UserInterface::interactWithManager() {
    while (true) {
        system("cls");
        std::cout << "1. ������ ������\n2. ������ �������\n��� ������ ������� q\n�������� ����� ����: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            ptrExpenseInputScreen = new ExpenseInputScreen(ptrExpensesList);
            while (choice != 'n') {
                system("cls");
                ptrExpenseInputScreen->setExpense('r');
                std::cout << "������� ������ ��� ���� ������? y|n ";
                std::cin >> choice;
            }
            delete ptrExpenseInputScreen;
            break;
        case '2':
            ptrExpenseInputScreen = new ExpenseInputScreen(ptrExpensesList);
            while (choice != 'n') {
                system("cls");
                ptrExpenseInputScreen->setExpense('p');
                std::cout << "������� ������ ��� ���� �������? y|n ";
                std::cin >> choice;
            }
            delete ptrExpenseInputScreen;
            break;
        case 'q':
            choosePosition();
            return;
        }
    }
}
