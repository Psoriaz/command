#ifndef SALESLIST_H
#define SALESLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "Sale.h"

class SalesList {
private:
    std::vector<Sale*> vectPtrsSales;
    std::vector<Sale*>::iterator iter;

public:
    ~SalesList();
    void insertSale(Sale*);
    void displayTable();
    double getSum();
    int getLastItemId();
};

#endif
