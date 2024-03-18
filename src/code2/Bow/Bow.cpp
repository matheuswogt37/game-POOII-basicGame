#include "./Bow.hpp";

Bow::Bow(std::string name, int att, int val, int mult) : Item(name, att, val, mult) {};
Bow::~Bow(){};

void Bow::showItem() {
    std::cout << "bow " << this->getName() << " | +" << this->getValue() << this->getNameAttribute() << "\n";
}