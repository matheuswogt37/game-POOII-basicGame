#include "./Staff.hpp"

void Staff::showItem() {
    std::cout << "staff " << this->getName() << " | +" << this->getValue() << this->getNameAttribute() << "\n";
}