#include "./Staff.hpp";

Staff::Staff(std::string name, int att, int val, int mult) : Item(name, att, val, mult) {};
Staff::~Staff(){};

void Staff::showItem() {
    std::cout << "staff " << this->getName() << " | +" << this->getValue() << this->getNameAttribute() << "\n";
}