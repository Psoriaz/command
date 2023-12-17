#ifndef ANNUALREPORT_H
#define ANNUALREPORT_H

#include "SalesList.h"
#include "ExpensesList.h"
#include <iostream>
#include <iomanip>

class AnnualReport {
private:
    SalesList* ptrSalesList;
    ExpensesList* ptrExpensesList;
    double incomes, expenses;

public:
    AnnualReport(SalesList* ptrSales, ExpensesList* ptrExpenses);
    void display();
};

#endif
