#include "SaleInputScreen.h"

SaleInputScreen::SaleInputScreen(SalesList* _ptrSalesList, ProductionList* _ptrProductionList) : ptrSalesList(_ptrSalesList), ptrProductionList(_ptrProductionList) {}

void SaleInputScreen::setSale() {
    double itemPrice;
    std::string itemName;
    int lastItemId;
    std::string currentDate = getCurrentDate();

    ptrProductionList->displayTable();

    std::cout << "\nВведите ID проданного товара из таблицы выше ";
    std::cin >> productId;

    itemPrice = ptrProductionList->getPriceById(productId);

    if (itemPrice == 0.0) {
        return;
    }

    itemName = ptrProductionList->getNameById(productId);

    std::cout << "Введите количество проданного товара ";
    std::cin >> quantity;

    if (quantity < 1) {
        std::cout << "Количество не может быть меньше 1" << std::endl;
        return;
    }

    lastItemId = ptrSalesList->getLastItemId();

    totalCost = quantity * itemPrice;

    ptrSalesList->insertSale(new Sale(lastItemId + 1, itemName, quantity, totalCost, currentDate));

    std::cout << "Продажа зафиксирована, выручка составила: " << totalCost << std::endl;
}
