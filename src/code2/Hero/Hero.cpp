#include "./Hero.hpp";

Hero::Hero(std::string name, int life, int stre, int inte, int dext, int dama, int resi) : Entity(name, life, stre, inte, dext, dama, resi)
{
    this->weapon = NULL;
    this->accessorie1 = NULL;
    this->accessorie2 = NULL;
};
Hero::~Hero(){};

void Hero::setAccessorie1(Item *item)
{
    // remove old accessories status
    switch (this->accessorie1->getAttribute())
    {
    case 1: // str
        this->setStrenght((this->getStrenght() - this->accessorie1->getValue()));
        break;
    case 2: // int
        this->setIntelligence((this->getIntelligence() - this->accessorie1->getValue()));
        break;
    case 3: // dex
        this->setDexterity((this->getDexterity() - this->accessorie1->getValue()));
        break;

    default:
        break;
    }

    // up new accessories status
    switch (item->getAttribute())
    {
    case 1: // str
        this->setStrenght((this->getStrenght() + item->getValue()));
        break;
    case 2: // int
        this->setIntelligence((this->getIntelligence() + item->getValue()));
        break;
    case 3: // dex
        this->setDexterity((this->getDexterity() + item->getValue()));
        break;

    default:
        break;
    }

    this->accessorie1->discardItem();
    this->accessorie1 = item;
    this->accessorie1->takeItem();
}

void Hero::setAccessorie2(Item *item)
{
    // remove old accessories status
    switch (this->accessorie2->getAttribute())
    {
    case 1: // str
        this->setStrenght((this->getStrenght() - this->accessorie2->getValue()));
        break;
    case 2: // int
        this->setIntelligence((this->getIntelligence() - this->accessorie2->getValue()));
        break;
    case 3: // dex
        this->setDexterity((this->getDexterity() - this->accessorie2->getValue()));
        break;

    default:
        break;
    }

    // up new accessories status
    switch (item->getAttribute())
    {
    case 1: // str
        this->setStrenght((this->getStrenght() + item->getValue()));
        break;
    case 2: // int
        this->setIntelligence((this->getIntelligence() + item->getValue()));
        break;
    case 3: // dex
        this->setDexterity((this->getDexterity() + item->getValue()));
        break;

    default:
        break;
    }

    this->accessorie2->discardItem();
    this->accessorie2 = item;
    this->accessorie2->takeItem();
}

void Hero::equipW(Item *item)
{
    if (item->getTaked())
    {
        std::cout << "weapon " << item->getName() << " alredy equip by someone\n";
    }
    else
    {
        if (this->weapon != NULL)
        {
            std::cout << "weapon " << this->weapon->getName() << " is replaced by " << item->getName() << "\n";
        }
        this->setWeapon(item);
    }
}

void Hero::equipAcc(Item *item)
{
    if (this->accessorie1 == NULL)
    {
        this->setAccessorie1(item);
    }
    else
    {
        if (this->accessorie2 == NULL)
        {
            std::cout << "accessorie " << this->accessorie1->getName() << " is replaced by " << item->getName() << "\n";
        }
        this->setAccessorie2(item);
    }
}

void Hero::unequipW()
{
    this->weapon->discardItem();
    this->weapon = NULL;
}

void Hero::unequipAcc(int slot)
{
    switch (slot)
    {
    case 1:
        this->accessorie1->discardItem();
        this->accessorie1 = NULL;
        break;

    case 2:
        this->accessorie2->discardItem();
        this->accessorie2 = NULL;
        break;

    default:
        break;
    }
}

void Hero::calcFDamage()
{
    if (this->weapon != NULL)
    {
        int attVal;
        switch (this->weapon->getAttribute())
        {
        case 1:
            attVal = this->getStrenght();
            break;
        case 2:
            attVal = this->getIntelligence();
            break;
        case 3:
            attVal = this->getDexterity();
            break;
        
        default:
            break;
        }
        this->setFDamage((this->getDamage() + attVal + this->weapon->getValue()));
    } else {
        this->setFDamage(((this->getStrenght() + this->getIntelligence() + this->getDexterity()) / 3));
    }
}

void Hero::calcFGuard() {
    this->setFGuard(this->getResistence());
}

void Hero::setWeapon(Item *item)
{
    this->weapon->discardItem();
    this->weapon = item;
    this->weapon->takeItem();
}

void Hero::showItem(Item *item)
{
    if (item != NULL)
    {
        std::cout << item->getName() << " | +" << item->getValue() << item->getNameAttribute() << "\n";
    }
}

void Hero::showInv()
{
    this->showItem(this->weapon);
    this->showItem(this->accessorie1);
    this->showItem(this->accessorie2);
}