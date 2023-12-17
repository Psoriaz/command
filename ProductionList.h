#ifndef PRODUCTIONLIST_H
#define PRODUCTIONLIST_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <regex>
#include <locale>
#include <codecvt>
#include "Production.h"

class ProductionList {
private:
    std::vector<Production*> vectPtrsProduction;
    std::vector<Production*>::iterator iter;

public:
    void loadFromFile(const std::string& filename);
    void displayTable();
    double getPriceById(int id);
    std::string getNameById(int id);
    ~ProductionList();
};

#endif
