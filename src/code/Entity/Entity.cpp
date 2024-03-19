#include "./Entity.hpp"

Entity::Entity(std::string name, int life, int stre, int inte, int dext, int dama, int resi) {
    this->name = name;
    this->life = life;
    this->strenght = stre;
    this->intelligence = inte;
    this->dexterity = dext;
    this->damage = dama;
    this->resistence = resi;
}

std::string Entity::getName() {
    return this->name;
}

int Entity::getLife() {
    return this->life;
}
void Entity::setLife(int l) {
    this->life = l;
}

int Entity::getStrenght() {
    return this->strenght;
}
void Entity::setStrenght(int s) {
    this->strenght = s;
}

int Entity::getIntelligence() {
    return this->intelligence;
}
void Entity::setIntelligence(int i) {
    this->intelligence = i;
}

int Entity::getDexterity() {
    return this->dexterity;
}
void Entity::setDexterity(int d) {
    this->dexterity = d;
}

int Entity::getDamage() {
    return this->damage;
}
void Entity::setDamage(int d) {
    this->damage = d;
}

int Entity::getResistence() {
    return this->resistence;
}
void Entity::setResistence(int r) {
    this->resistence = r;
}

int Entity::getFDamage() {
    return this->finalDamage;
}
void Entity::setFDamage(int a) {
    this->finalDamage = a;
}

int Entity::getFGuard() {
    return this->finalGuard;
}
void Entity::setFGuard(int a) {
    this->finalGuard = a;
}

void Entity::calcFDamage(Item *item) {}
void Entity::calcFDamage() {}
void Entity::calcFGuard(Item *item) {}
void Entity::calcFGuard() {}