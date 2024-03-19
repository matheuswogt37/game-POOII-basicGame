#include "./Bow.hpp"




void Bow::showItem() {
    std::cout << "bow " << this->getName() << " | +" << this->getValue() << this->getNameAttribute() << "\n";
}