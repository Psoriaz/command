#ifndef SALE_H
#define SALE_H

#include <string>

class Sale {
public:
    int id;
    std::string name;
    int quantity;
    double sum;
    std::string date;

    Sale(int _id, const std::string& _name, int _quantity, double _sum, const std::string& _date);
};

#endif
