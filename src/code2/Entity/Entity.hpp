#ifndef Entity_hpp
#define Entity_hpp
#include <iostream>
#include "../Item/Item.hpp";

class Entity {
    private:
        std::string name;
        int life, strenght, intelligence, dexterity, damage, resistence, finalDamage, finalGuard;
    protected:
        Entity(std::string name, int life, int stre, int inte, int dext, int dama, int resi);
        ~Entity(){};
    public:
        std::string getName();
        
        int getLife();
        void setLife(int l);

        int getStrenght();
        void setStrenght(int s);

        int getIntelligence();
        void setIntelligence(int i);

        int getDexterity();
        void setDexterity(int d);

        int getDamage();
        void setDamage(int d);

        int getResistence();
        void setResistence(int r);

        int getFDamage();
        void setFDamage(int i);
        int getFGuard();
        void setFGuard(int i);

        virtual void calcFDamage(Item *item);
        virtual void calcFDamage();
        virtual void calcFGuard(Item *item);
        virtual void calcFGuard();
};






#endif