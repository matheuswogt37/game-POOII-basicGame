#include "./Monster.hpp"

Monster::Monster(std::string name, int life, int stre, int inte, int dext, int dama, int resi, int typeDamage) : Entity(name, life, stre, inte, dext, dama, resi)
{
    this->typeDamage = typeDamage;
}

void Monster::calcFDamage()
{
    int attDam;
    switch (this->typeDamage)
    {
    case 1:
        attDam = this->getStrenght();
        break;
    case 2:
        attDam = this->getIntelligence();
        break;
    case 3:
        attDam = this->getDexterity();
        break;

    default:
        break;
    }
    this->setFDamage((this->getDamage() + attDam));
}
void Monster::calcFGuard()
{
    this->setFGuard(this->getResistence());
}