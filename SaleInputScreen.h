#ifndef SALEINPUTSCREEN_H
#define SALEINPUTSCREEN_H

#include <iostream>
#include <funcs.h>
#include <SalesList.h>
#include <ProductionList.h>

class SaleInputScreen {
private:
    SalesList* ptrSalesList;
    ProductionList* ptrProductionList;
    int productId;
    int quantity;
    double totalCost;
public:
    SaleInputScreen(SalesList* _ptrSalesList, ProductionList* _ptrProductionList);
    void setSale();
};

#endif
