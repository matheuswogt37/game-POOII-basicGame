#ifndef Bow_hpp
#define Bow_hpp
#include "../Item/Item.hpp";

class Bow : public Item {
    public:
        Bow(std::string name, int att, int val, int mult) : Item(name, att, val, mult) {}
        ~Bow();
        void showItem();
};

#endif