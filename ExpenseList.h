#ifndef EXPENSESLIST_H
#define EXPENSESLIST_H

#include <vector>
#include <unordered_map>
#include "Expense.h"

class ExpensesList {
private:
    std::vector<Expense*> vectPtrsExpenses;
    std::vector<Expense*>::iterator iter;

public:
    ~ExpensesList();
    void insertExpense(Expense*);
    void displayTable();
    double displaySummary();
    int getLastItemId();
};

#endif
