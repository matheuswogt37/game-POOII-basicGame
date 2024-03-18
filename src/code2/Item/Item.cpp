#include "./Item.hpp";

Item::Item(std::string n, int att, int val, int mult)
{
    this->name = n;
    this->attribute = att;
    this->value = val;
    this->multStatus = mult;
}
Item::~Item(){};

std::string Item::getNameAttribute()
{
    switch (this->attribute)
    {
    case 1:
        return "str";
        break;
    case 2:
        return "int";
        break;
    case 3:
        return "dex";
        break;

    default:
        break;
    }
}

void Item::takeItem()
{
    this->taked = true;
}

void Item::discardItem()
{
    this->taked = false;
}

std::string Item::getName()
{
    return this->name;
}

int Item::getAttribute()
{
    return this->attribute;
}

int Item::getValue()
{
    return this->value;
}

int Item::getMultStatus()
{
    return this->multStatus;
}

bool Item::getTaked()
{
    return this->taked;
}

void Item::showItem() {
    std::cout << this->name << " | +" << this->value << this->getNameAttribute() << "\n";
};