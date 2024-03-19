#ifndef Battle_hpp
#define Battle_hpp
#include <iostream>

class Battle {
    private:
        int initiative;
        int heroFDamage, heroFGuard, heroLife;
        int monsterFDamage, monsterFGuard, monsterLife;

    protected:
    public:
        ~Battle();
        Battle(int hFDamage, int hFGuard, int hLife, int mFDamage, int mFGuard, int mLife);
        int randInitiative();
        int randCriticalDam();
        bool fight();
};

#endif