#include "Character.h"
#include <string>
#include <iostream>

using namespace std;
Character::Character(HeroType t, const string & n, double hp, double atk): type(t), name(n), health(hp), attackStrength(atk){}
HeroType Character::getType() const
{
    return type;
}
const string & Character::getName() const
{
    return name;
}
int Character::getHealth() const
{
    return static_cast<int>(health);
}
void Character::setHealth(double h)
{
    health = h;
}
void Character::damage(double d)
{
    health -= d;   
}
bool Character::isAlive() const
{
    return (getHealth() > 0);
}

