#include "./Sword.hpp";

Sword::Sword(std::string name, int att, int val, int mult) : Item(name, att, val, mult) {};
Sword::~Sword(){};

void Sword::showItem() {
    std::cout << "sword " << this->getName() << " | +" << this->getValue() << this->getNameAttribute() << "\n";
}