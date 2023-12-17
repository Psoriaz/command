#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense {
public:
    int id;
    std::string category;
    double amount;
    std::string date;

    Expense(int _id, const std::string& _category, double _amount, const std::string& _date);
};

#endif
