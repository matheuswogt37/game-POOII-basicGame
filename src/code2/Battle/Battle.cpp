#include "./Battle.hpp";

Battle::Battle(int hFDamage, int hFGuard, int hLife, int mFDamage, int mFGuard, int mLife) {
    this->heroFDamage = hFDamage;
    this->heroFGuard = hFGuard;
    this->heroLife = hLife;

    this->monsterFDamage = mFDamage;
    this->monsterFGuard = mFGuard;
    this->monsterLife = mLife;
}

Battle::~Battle(){};

int Battle::randInitiative()
{
    return (rand() % 2) + 1;
}

int Battle::randCriticalDam()
{
    return (rand() % 10) + 1;
}

bool Battle::fight()
{
    int tempDamage;
    int attackerDamage, defenderDamage, attackerLife, defenderLife, attaquerGuard, defenderGuard;
    this->initiative = randInitiative();


    if (this->initiative == 1)
    { // hero first
        attackerLife = this->heroLife;
        attackerDamage = this->heroFDamage;
        attaquerGuard = this->heroFGuard;
        defenderLife = this->monsterLife;
        defenderDamage = this->monsterFDamage;
        defenderGuard = this->monsterFGuard;
    }
    else
    { // monster first
        attackerLife = this->monsterLife;
        attackerDamage = this->monsterFDamage;
        attaquerGuard = this->monsterFGuard;
        defenderLife = this->heroLife;
        defenderDamage = this->heroFDamage;
        defenderGuard = this->heroFGuard;
    }

    while (attackerLife > 0 && defenderLife > 0)
    {
        tempDamage = attackerDamage - defenderGuard;
        if (tempDamage <= 0)
        {
            tempDamage = 1;
        }
        if (this->randCriticalDam() == 10)
        {
            tempDamage *= 2;
        }
        defenderLife -= tempDamage;
        if (defenderLife > 0)
        {
            tempDamage = defenderDamage - attaquerGuard;
            if (tempDamage <= 0)
            {
                tempDamage = 1;
            }
            if (this->randCriticalDam() == 10)
            {
                tempDamage *= 2;
            }
            attackerLife -= tempDamage;
        }
    }

    if (initiative == 1) {
        if (attackerLife <= 0) {
            return false;
        }
        return true;
    } else {
        if (defenderLife <= 0) {
            return false;
        }
        return true;
    }
}