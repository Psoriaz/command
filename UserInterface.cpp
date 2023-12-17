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
    std::cout << "Выберите свою должность:\n1. Кассир\n2. Бухгалтер\n3. Менеджер\nДля выхода нажмите q\nВыберите пункт меню: ";
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
        std::cout << "Неизвестный пункт";
        break;
    }
}

void UserInterface::interactWithCashier() {
    while (true) {
        system("cls");
        std::cout << "1. Ввести новую продажу\nДля выхода нажмите q\nВыберите пункт меню: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            ptrSaleInputScreen = new SaleInputScreen(ptrSalesList, ptrProductionList);
            while (choice != 'n') {
                system("cls");
                ptrSaleInputScreen->setSale();
                std::cout << "Желаете ввести еще одну продажу? y|n ";
                std::cin >> choice;
            }
            delete ptrSaleInputScreen;
            break;
        case 'q':
            choosePosition();
            return;
        default:
            std::cout << "Неизвестный пункт";
            break;
        }
    }
}

void UserInterface::interactWithAccountant() {
    while (true) {
        system("cls");
        std::cout << "1. Вывести таблицу доходов\n2. Вывести таблицу расходов\n3. Вывести годовой отчет\n4. Ввести налог\n5. Ввести выплату сотруднику\nДля выхода нажмите q\nВыберите пункт меню: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            system("cls");
            ptrSalesList->displayTable();
            std::cout << "\nЧтобы вернуться в меню нажмите любую клавишу ";
            system("pause > nul");
            break;
        case '2':
            system("cls");
            ptrExpensesList->displayTable();
            std::cout << "\nЧтобы вернуться в меню нажмите любую клавишу ";
            system("pause > nul");
            break;
        case '3':
            ptrAnnualReport = new AnnualReport(ptrSalesList, ptrExpensesList);
            ptrAnnualReport->display();
            delete ptrAnnualReport;
            std::cout << "\nЧтобы вернуться в меню нажмите любую клавишу ";
            system("pause > nul");
            break;
        case '4':
            ptrExpenseInputScreen = new ExpenseInputScreen(ptrExpensesList);
            while (choice != 'n') {
                system("cls");
                ptrExpenseInputScreen->setExpense('t');
                std::cout << "Желаете ввести еще один налог? y|n ";
                std::cin >> choice;
            }
            delete ptrExpenseInputScreen;
            break;
        case '5':
            ptrExpenseInputScreen = new ExpenseInputScreen(ptrExpensesList);
            while (choice != 'n') {
                system("cls");
                ptrExpenseInputScreen->setExpense('s');
                std::cout << "Желаете ввести еще одну выплату? y|n ";
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
        std::cout << "1. Ввести аренду\n2. Ввести закупку\nДля выхода нажмите q\nВыберите пункт меню: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            ptrExpenseInputScreen = new ExpenseInputScreen(ptrExpensesList);
            while (choice != 'n') {
                system("cls");
                ptrExpenseInputScreen->setExpense('r');
                std::cout << "Желаете ввести еще одну аренду? y|n ";
                std::cin >> choice;
            }
            delete ptrExpenseInputScreen;
            break;
        case '2':
            ptrExpenseInputScreen = new ExpenseInputScreen(ptrExpensesList);
            while (choice != 'n') {
                system("cls");
                ptrExpenseInputScreen->setExpense('p');
                std::cout << "Желаете ввести еще одну закупку? y|n ";
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
