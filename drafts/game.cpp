#include <iostream>
#include <string>
using namespace std;

class Collect {
    public:
        
};

class Item
{
public:
    string name;
    int type;      // 1 - weapon | 2 - ring
    int attribute; // 1 - strenght | 2 - intelligence | 3 - dexterity | the weapon scales with attribute, the ring buffs the attribute
    int value;     // damage for weapon | buff for ring
    double multStatus;

    Item(); // constructor when no item stored

    void switchItem(string n, int t, int a, int v, double multi)
    {
        this->name = n;
        this->type = t;
        this->attribute = a;
        this->multStatus = multi;
        this->value = v * multi;
    }

    string getAttribute() {
        if (this->attribute == 1)
        {
            cout << "str";
        }
        else if (this->attribute == 2)
        {
            cout << "int";
        }
        else
        {
            cout << "dex";
        }
    }

    void showItem()
    {
        cout << this->name << " - +" << this->value << getAttribute();
    }

    int ifNull()
    {
        if (empty(this->name))
        {
            return 1;
        }
        return 0;
    }
};

class Weapon : public Item
{
public:
    void showItem()
    {
        cout << "weapon " << this->name << " - +" << this->value << getAttribute();
    };
};

class Ring : public Item {
    public:
    void showItem()
    {
        cout << "ring " << this->name << " - +" << this->value << getAttribute();
    };
};

class Entity
{
public:
    string name;
    int life;
    int strenght;
    int intelligence;
    int dexterity;
    int damage;
    Item weapon;
    Item ring;

    void attack();
    void guard();

    Entity(string name, int life, int strenght, int intelligence, int dexterity, int damage, double multStatus)
    {
        this->name = name;
        this->life = life * multStatus;
        this->strenght = strenght * multStatus;
        this->intelligence = intelligence * multStatus;
        this->dexterity = dexterity * multStatus;
        this->damage = damage * multStatus;
    };
};

class Hero : public Entity
{
public:
    int score;

    void addItem(Item item)
    {
        string type;
        char option;
        if (item.type == 1)
        {
            type = "weapon";
        }
        else
        {
            type = "ring";
        }
        if (!this->weapon.ifNull())
        {
            cout << "currently occupied " << type << " slot! want to change anyway (y/n)";
            // receive option
            if (option == 'y')
            {
                this->weapon.switchItem(item.name, item.type, item.attribute, item.value, item.multStatus);
            }
        }
        else
        {
            this->weapon.switchItem(item.name, item.type, item.attribute, item.value, item.multStatus);
        }
    }
};

class Monster : public Entity
{
public:
    int points;
    string asciiArt;
    double multStatus;

    Monster(string name, int life, int strenght, int intelligence, int dexterity, int damage, int p, string a, double m) : Entity(name, life, strenght, intelligence, dexterity, damage)
    {
        this->points = p;
        this->asciiArt = a;
        this->multStatus = m;
    }
};

class Stage
{
public:
    int level;
    double difficult;
    double multiplierItemStatus;
    int chanceMonsterEvent;
    int path;
    int lastPath;
    Item weaponLoot;
    Item ringLoot;

    Stage()
    {
        this->level = 1;
        this->difficult = 1;
        this->multiplierItemStatus = 1;
        this->chanceMonsterEvent = 35;
        this->path = 0; // 0 - 8
        this->lastPath = 0;
    }

    void monsterEvent(){
        // create monster, go to battle
    };

    void itemEvent(){
        // create item, let hero choose
    };

    void randomEvent()
    {
        int realChanceMonsterEvent = (path * ((70 - chanceMonsterEvent) / 8)) + chanceMonsterEvent; // (path * ((max - min) / 8 [max_path])) + min;
        int RNG = rand() % 100 + 1;

        if (RNG <= realChanceMonsterEvent)
        {
            monsterEvent();
        }
        else
        {
            itemEvent();
        }
    }

    void enterRoom(int room)
    { // 1 - left | 2 - right | 0 - middle

        if (room != 0)
        {
            // first path
            if (lastPath == 0)
            {
                lastPath = room;
            }

            // difficult generator
            if (lastPath == room)
            {
                difficult += ((double)1 / 8);
            }
            else
            {
                difficult -= ((double)1 / 8);
            }

            // multiplier generator
            if (lastPath == room)
            {
                multiplierItemStatus += ((double)2 / 8);
            }
            else
            {
                multiplierItemStatus -= ((double)2 / 8);
            }
        }

        randomEvent();

        level++;
    }
};

int main()
{

    return 0;
}