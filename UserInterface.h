#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "SaleInputScreen.h"
#include "ExpenseInputScreen.h"
#include "ProductionList.h"
#include "SalesList.h"
#include "ExpensesList.h"
#include "AnnualReport.h"

class UserInterface {
private:
    SaleInputScreen* ptrSaleInputScreen;
    ExpenseInputScreen* ptrExpenseInputScreen;
    ProductionList* ptrProductionList;
    SalesList* ptrSalesList;
    ExpensesList* ptrExpensesList;
    AnnualReport* ptrAnnualReport;
    char choice;

public:
    UserInterface();
    ~UserInterface();
    void choosePosition();
    void interactWithCashier();
    void interactWithAccountant();
    void interactWithManager();
};

#endif
