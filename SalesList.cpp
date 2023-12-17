#include "SalesList.h"

SalesList::~SalesList() {
    while (!vectPtrsSales.empty()) {
        iter = vectPtrsSales.begin();
        delete *iter;
        vectPtrsSales.erase(iter);
    }
}

void SalesList::insertSale(Sale* ptrSale) {
    vectPtrsSales.push_back(ptrSale);
}

void SalesList::displayTable() {
    if (vectPtrsSales.size() == 0) {
        std::cout << "Список продаж пуст";
    }
    else {
        std::cout << std::left << std::setw(5) << "ID" << std::setw(30) << "Источник" << std::setw(15) << "Количество" << std::setw(15) << "Сумма" << std::setw(15) << "Дата" << std::endl;
            std::cout << "================================================================================" << std::endl;

        iter = vectPtrsSales.begin();

        while(iter != vectPtrsSales.end()) {
            std::cout << std::left << std::setw(5) << (*iter)->id << std::setw(30) << (*iter)->name << std::setw(15) << (*iter)->quantity << std::setw(15) << (*iter)->sum << std::setw(15) << (*iter)->date << "\n";
            iter++;
        }
    }
}

double SalesList::getSum() {
    double salesSum = 0.0;

    iter = vectPtrsSales.begin();

    while (iter != vectPtrsSales.end()) {
        salesSum += (*iter)->sum;
        iter++;
    }

    return salesSum;
}

int SalesList::getLastItemId() {
    Sale* lastItem;
    if (vectPtrsSales.size() > 0) {
        lastItem = vectPtrsSales.back();
        return lastItem->id;
    }
    else {
        return 0;
    }
}
