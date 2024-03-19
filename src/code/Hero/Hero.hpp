#ifndef Hero_hpp
#define Hero_hpp
#include "../Entity/Entity.hpp"

class Hero : public Entity {
    private:
        Item *weapon;
        Item *accessorie1;
        Item *accessorie2;
        int score;
    public:
        Hero(std::string name, int life, int stre, int inte, int dext, int dama, int resi);
        ~Hero();
        void equipW(Item *item);
        void equipAcc(Item *item);
        void unequipW();
        void unequipAcc(int slot);

        void calcFDamage();
        void calcFGuard();

        void setWeapon(Item *w);

        void setAccessorie1(Item *a);

        void setAccessorie2(Item *a);

        

        void showItem(Item *item);
        void showInv();

};


#endif