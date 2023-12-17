#include "ProductionList.h"

ProductionList::~ProductionList() {
    while (!vectPtrsProduction.empty()) {
        iter = vectPtrsProduction.begin();
        delete *iter;
        vectPtrsProduction.erase(iter);
    }
}

void ProductionList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "������ ��� �������� �����: " << filename << std::endl;
        return;
    }

    int id = 0;

    std::string line;
    std::regex pattern(R"((.*)\s+(\d+\.\d+))");

    while (std::getline(file, line)) {
        std::smatch matches;

        if (std::regex_match(line, matches, pattern)) {
            std::string name = matches[1];
            double price = std::stod(matches[2]);

            vectPtrsProduction.push_back(new Production(id, name, price));
            id++;
        }
    }

    file.close();
}

void ProductionList::displayTable() {
    if (vectPtrsProduction.empty()) {
        std::cout << "������ ��������� ����";
    }
    else {
        std::cout << std::left << std::setw(5) <<  "ID" << std::setw(30) << "��������" << std::setw(10) << "���� �� �����" << std::endl;
        std::cout << "=============================================" << std::endl;

        iter = vectPtrsProduction.begin();

        while(iter != vectPtrsProduction.end()) {
            std::cout << std::left << std::setw(5) << (*iter)->id << std::setw(30) << (*iter)->name << std::setw(10) << (*iter)->price << "\n";
            iter++;
        }
    }
}

double ProductionList::getPriceById(int id) {
    iter = vectPtrsProduction.begin();

    while (iter != vectPtrsProduction.end()) {
        if ((*iter)->id == id) {
            return (*iter)->price;
        }
        iter++;
    }

    std::cout << "������� � ID " << id << " �� ������." << std::endl;
    return 0.0;
}

std::string ProductionList::getNameById(int id) {
    iter = vectPtrsProduction.begin();

    while (iter != vectPtrsProduction.end()) {
        if ((*iter)->id == id) {
            return (*iter)->name;
        }
        iter++;
    }

    return ""; // �������� ������� ������ ������, ����� �������� �������������� � ��������������
}
