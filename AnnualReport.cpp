#include "AnnualReport.h"

AnnualReport::AnnualReport(SalesList* _ptrSalesList, ExpensesList* _ptrExpensesList) : ptrSalesList(_ptrSalesList), ptrExpensesList(_ptrExpensesList) {}

void AnnualReport::display() {
    system("cls");

    incomes = ptrSalesList->getSum();
    std::cout << std::left << std::setw(15) << "���������" << std::setw(15) << "�����" << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << std::left << std::setw(15) << "������" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "�������:";
    std::cout << std::left << std::setw(15) << incomes << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "�������" << std::endl;
    std::cout << "------------------------------" << std::endl;
    expenses = ptrExpensesList->displaySummary();
    std::cout << "------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "����:" << std::setw(15) << (incomes - expenses) << std::endl;
}
