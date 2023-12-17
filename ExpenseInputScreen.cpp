#include "ExpenseInputScreen.h"

ExpenseInputScreen::ExpenseInputScreen(ExpensesList* _ptrExpensesList) : ptrExpensesList(_ptrExpensesList) {}

void ExpenseInputScreen::setExpense(char cat) {
    std::string category;
    int lastItemId;
    std::string date;

    switch (cat) {
    case 't':
        std::cout << "Введите сумму уплаченного налога ";
        category = "Налоги";
        break;
    case 's':
        std::cout << "Введите сумму выплаты ";
        category = "Выплаты сотрудникам";
        break;
    case 'r':
        std::cout << "Введите сумму аренды ";
        category = "Аренда";
        break;
    case 'p':
        std::cout << "Введите сумму, на которую была осуществлена закупка ";
        category = "Закупки";
        break;
    }

    std::cin >> totalSum;

    if (totalSum < 1) {
        std::cout << "Сумма не может быть меньше 1" << std::endl;
        return;
    }

    std::cout << "Введите дату операции ";
    std::cin >> date;

    lastItemId = ptrExpensesList->getLastItemId();

    ptrExpensesList->insertExpense(new Expense(lastItemId + 1, category, totalSum, date));
}
