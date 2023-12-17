#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <string>

class Production {
public:
    int id;
    std::string name;
    double price;

    Production(int _id, const std::string& _name, double _price);
    ~Production();
};

#endif
