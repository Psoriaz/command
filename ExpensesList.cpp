#include "ExpensesList.h"
#include <iostream>
#include <iomanip>

ExpensesList::~ExpensesList() {
    while (!vectPtrsExpenses.empty()) {
        iter = vectPtrsExpenses.begin();
        delete *iter;
        vectPtrsExpenses.erase(iter);
    }
}

void ExpensesList::insertExpense(Expense* ptrExpense) {
    vectPtrsExpenses.push_back(ptrExpense);
}

void ExpensesList::displayTable() {
    if (vectPtrsExpenses.size() == 0) {
        std::cout << "������ �������� ����";
    }
    else {
        std::cout << std::left << std::setw(5) <<  "ID" << std::setw(20) << "���������" << std::setw(15) << "�����" << std::setw(15) << "����" << std::endl;
        std::cout << "=======================================================" << std::endl;

        iter = vectPtrsExpenses.begin();

        while(iter != vectPtrsExpenses.end()) {
            std::cout << std::left << std::setw(5) << (*iter)->id << std::setw(20) << (*iter)->category << std::setw(15) << (*iter)->amount << std::setw(15) << (*iter)->date << std::endl;
            iter++;
        }
    }
}

double ExpensesList::displaySummary() {
    double totalExpenses = 0.0;
    std::unordered_map<std::string, double> sumMap;
    std::unordered_map<std::string, double>::iterator mapIter;

    iter = vectPtrsExpenses.begin();

    while (iter != vectPtrsExpenses.end()) {
        mapIter = sumMap.find((*iter)->category);

        if (mapIter != sumMap.end()) {
            mapIter->second += (*iter)->amount;
        } else {
            sumMap[(*iter)->category] = (*iter)->amount;
        }

        iter++;
    }

    mapIter = sumMap.begin();

    while (mapIter != sumMap.end()) {
        std::cout << std::left << std::setw(15) << mapIter->first << std::setw(15) << mapIter->second << std::endl;
        totalExpenses += mapIter->second;
        ++mapIter;
    }

    return totalExpenses;
}

int ExpensesList::getLastItemId() {
    Expense* lastItem;
    if (vectPtrsExpenses.size() > 0) {
        lastItem = vectPtrsExpenses.back();
        return lastItem->id;
    }
    else {
        return 0;
    }
}
