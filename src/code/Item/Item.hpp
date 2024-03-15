#ifndef Item_hpp
#define Item_hpp
#include<iostream>

class Item{
    protected:
        std::string name;
        int type, attribute, value, multStatus;

        void showItem();
        void ifNull();
        std::string getNameAttribute();
};
#endif