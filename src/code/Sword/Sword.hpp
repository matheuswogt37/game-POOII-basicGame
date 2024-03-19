#ifndef Sword_hpp
#define Sword_hpp
#include "../Item/Item.hpp"

class Sword : public Item {
    public:
        Sword(std::string name, int att, int val, int mult) : Item(name, att, val, mult) {}
        ~Sword();
        void showItem();
};

#endif