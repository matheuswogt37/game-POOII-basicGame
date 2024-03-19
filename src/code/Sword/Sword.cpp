#include "./Sword.hpp"

void Sword::showItem() {
    std::cout << "sword " << this->getName() << " | +" << this->getValue() << this->getNameAttribute() << "\n";
}