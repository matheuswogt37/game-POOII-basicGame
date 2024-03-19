#ifndef Item_hpp
#define Item_hpp
#include <iostream>
#include "../Collected/Collected.hpp"
#include "../ItemMenu/ItemMenu.hpp"

class Item : public Collected, ItemMenu{
    private:
        std::string name;
        int attribute, value, multStatus;
        bool taked;
    public:
        Item (std::string n, int att, int val, int mult);
        ~Item();
        bool ifNull();
        std::string getNameAttribute();
        void takeItem();
        void discardItem();
        std::string getName();
        int getAttribute();
        int getValue();
        int getMultStatus();
        bool getTaked();
        void showItem();

};


















#endif