#ifndef Staff_hpp
#define Staff_hpp
#include "../Item/Item.hpp"

class Staff : public Item {
    public:
        Staff(std::string name, int att, int val, int mult) : Item(name, att, val, mult) {}
        ~Staff();
        void showItem();
};

#endif