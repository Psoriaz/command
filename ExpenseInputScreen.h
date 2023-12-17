#ifndef EXPENSEINPUTSCREEN_H
#define EXPENSEINPUTSCREEN_H

#include "ExpensesList.h"
#include <iostream>

class ExpenseInputScreen {
private:
    ExpensesList* ptrExpensesList;
    double totalSum;

public:
    ExpenseInputScreen(ExpensesList* _ptrExpensesList);
    void setExpense(char cat);
};

#endif
