#include <iostream>
// sleep in linux
#include <unistd.h>

#include "./Battle/Battle.hpp"
#include "./Hero/Hero.hpp"
#include "./Monster/Monster.hpp"
#include "./Entity/Entity.hpp"
#include "./Sword/Sword.hpp"
#include "./Staff/Staff.hpp"
#include "./Bow/Bow.hpp"

struct StructRandMonster{
    std::string name;
    int life, stre, inte, dext, dama, resi, typeDamage;
};

void clearConsole()
{
    system("clear");
}

void randMonster(StructRandMonster *rand) {
                            // balaced        str         dex        int       freak
    const char* names[5] = {"chimera ant", "minotaur", "kappa", "dark mage", "goblin"};
    int life[5] = {60, 100, 35, 25, 20};
    int stre[5] = {20, 40, 10, 5, 5};
    int inte[5] = {20, 5, 10, 45, 2};
    int dext[5] = {25, 20, 30, 15, 3};
    int dama[5] = {60, 40, 50, 30, 20};
    int resi[5] = {30, 40, 25, 10, 5};
    int typeDamage[5] = {3, 1, 3, 2, 1};

    int nRand = std::rand() % 5;

    rand->name = names[nRand];
    rand->life = life[nRand];
    rand->stre = stre[nRand];
    rand->inte = inte[nRand];
    rand->dext = dext[nRand];
    rand->dama = dama[nRand];
    rand->resi = resi[nRand];
    rand->typeDamage = typeDamage[nRand];
}

int main()
{

    Hero *ptrHero;
    Item *ptrWeapon;
    Item *ptrAcc;
    Monster *ptrMonster;
    Battle *automaticBattle;
    StructRandMonster randomizerMonster;
    int cmd;
    bool hAlive;
    
    std::cout << "chose your class\n1 - warrior\n2 - mage\n3 - archer\n";
    std::cin >> cmd;
    switch (cmd)
    {
    case 1:
        ptrHero = new Hero("warrior", 100, 20, 5, 10, 15, 50);
        ptrAcc = new Item("str ring", 1, 10, 20);
        break;
    case 2:
        ptrHero = new Hero("mage", 50, 5, 30, 5, 20, 30);
        ptrAcc = new Item("int ring", 2, 10, 20);
        break;
    case 3:
        ptrHero = new Hero("archer", 75, 10, 5, 20, 20, 40);
        ptrAcc = new Item("dex ring", 3, 10, 20);
        break;

    default:
        std::cout << "wrong answer! deleting 'C:\\Windows\\system32'";
        return 0;
    }
    ptrHero->equipAcc(ptrAcc);
    
    clearConsole();

    std::cout << "chose your weapon\n1 - sword\n2 - staff\n3 - bow\n";
    std::cin >> cmd;

    switch (cmd)
    {
    case 1:
        ptrWeapon = new Sword("slasher", 1, 30, 20);
        break;
    case 2:
        ptrWeapon = new Staff("wind arcane", 2, 20, 20);
        break;
    case 3:
        ptrWeapon = new Bow("fast shot", 3, 25, 20);
        break;

    default:
        std::cout << "wrong answer! deleting 'C:\\Windows\\system32'";
        return 0;
    }

    ptrHero->equipW(ptrWeapon);

    ptrHero->calcFDamage();
    ptrHero->calcFGuard();

    hAlive = true;
    while (hAlive)
    {
        clearConsole();
        randMonster(&randomizerMonster);
        ptrMonster = new Monster(randomizerMonster.name, randomizerMonster.life, randomizerMonster.stre, randomizerMonster.inte, randomizerMonster.dext, randomizerMonster.dama, randomizerMonster.resi, randomizerMonster.typeDamage);
        ptrMonster->calcFDamage();
        ptrMonster->calcFGuard();
        std::cout << "you will fight against " << ptrMonster->getName() << "!\n";

        sleep(3);
        
        automaticBattle = new Battle(ptrHero->getFDamage(), ptrHero->getFGuard(), ptrHero->getLife(), ptrMonster->getFDamage(), ptrMonster->getFGuard(), ptrMonster->getLife());
        hAlive = automaticBattle->fight();
        clearConsole();
        if (hAlive) {
            std::cout << "your " << ptrHero->getName() << " win against " << ptrMonster->getName() << "! good job!\n";
            sleep(3);
            std::cout << "chose\n1 - battle another monster\n2 - end\n";
            std::cin >> cmd;
            if (cmd == 2) {
                hAlive = false;
            }
        } else {
            std::cout << "your " << ptrHero->getName() << " lose against " << ptrMonster->getName() << "! you die!\n";
            sleep(3);
        }
    }
    clearConsole();
    std::cout << "\nthis is the end of your jorney\n";
    sleep(3);
    std::cout << "\ntoday\n";

    return 0;
}