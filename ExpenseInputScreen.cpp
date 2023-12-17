#include "ExpenseInputScreen.h"

ExpenseInputScreen::ExpenseInputScreen(ExpensesList* _ptrExpensesList) : ptrExpensesList(_ptrExpensesList) {}

void ExpenseInputScreen::setExpense(char cat) {
    std::string category;
    int lastItemId;
    std::string date;

    switch (cat) {
    case 't':
        std::cout << "������� ����� ����������� ������ ";
        category = "������";
        break;
    case 's':
        std::cout << "������� ����� ������� ";
        category = "������� �����������";
        break;
    case 'r':
        std::cout << "������� ����� ������ ";
        category = "������";
        break;
    case 'p':
        std::cout << "������� �����, �� ������� ���� ������������ ������� ";
        category = "�������";
        break;
    }

    std::cin >> totalSum;

    if (totalSum < 1) {
        std::cout << "����� �� ����� ���� ������ 1" << std::endl;
        return;
    }

    std::cout << "������� ���� �������� ";
    std::cin >> date;

    lastItemId = ptrExpensesList->getLastItemId();

    ptrExpensesList->insertExpense(new Expense(lastItemId + 1, category, totalSum, date));
}
