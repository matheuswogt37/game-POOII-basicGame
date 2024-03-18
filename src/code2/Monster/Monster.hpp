#ifndef Monster_hpp
#define Monster_hpp
#include <iostream>
#include "../Entity/Entity.hpp";

class Monster : public Entity{
    private:
        int typeDamage;
    public:
        Monster(std::string name, int life, int stre, int inte, int dext, int dama, int resi, int typeDamage);
        ~Monster();
        void calcFDamage();
        void calcFGuard();
};

#endif