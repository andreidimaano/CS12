#include <string>
#include <iostream>
#include "Warrior.h"

using namespace std;

Warrior::Warrior(const string &n, double hp, double atk, string a):  Character(WARRIOR, n, hp, atk)
{
    allegiance = a;
}
void Warrior::attack(Character & opponent)
{
    double dam = 0.0;
    if(opponent.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(this->allegiance == opp.allegiance)
        {
            
            cout << "Warrior " << this->getName() << " does not attack Warrior " << opponent.getName() <<"." << endl
                 << "They share an allegiance with " << allegiance << "." << endl;
            return;
        }
    }
    dam = ((health/ MAX_HEALTH) * attackStrength); 
    opponent.damage(dam);
    cout << "Warrior " << this->getName() <<" attacks " << opponent.getName() << " --- SLASH!!" << endl
             << opponent.getName() << " takes " << dam << " damage." << endl;
}

/*Stores the warrior's allegiance as a string.
The warrior does not attack warriors that have the same allegiance.
The damage done by the warrior is the percentage of the warrior's health remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.
*/


