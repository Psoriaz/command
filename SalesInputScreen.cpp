#include "SaleInputScreen.h"

SaleInputScreen::SaleInputScreen(SalesList* _ptrSalesList, ProductionList* _ptrProductionList) : ptrSalesList(_ptrSalesList), ptrProductionList(_ptrProductionList) {}

void SaleInputScreen::setSale() {
    double itemPrice;
    std::string itemName;
    int lastItemId;
    std::string currentDate = getCurrentDate();

    ptrProductionList->displayTable();

    std::cout << "\n������� ID ���������� ������ �� ������� ���� ";
    std::cin >> productId;

    itemPrice = ptrProductionList->getPriceById(productId);

    if (itemPrice == 0.0) {
        return;
    }

    itemName = ptrProductionList->getNameById(productId);

    std::cout << "������� ���������� ���������� ������ ";
    std::cin >> quantity;

    if (quantity < 1) {
        std::cout << "���������� �� ����� ���� ������ 1" << std::endl;
        return;
    }

    lastItemId = ptrSalesList->getLastItemId();

    totalCost = quantity * itemPrice;

    ptrSalesList->insertSale(new Sale(lastItemId + 1, itemName, quantity, totalCost, currentDate));

    std::cout << "������� �������������, ������� ���������: " << totalCost << std::endl;
}
