#include <string>
#include <iostream>
#include "Wizard.h"

// Stores the wizard's rank as an int.

// When a wizard attacks another wizard, the damage done is the wizard's attack strength multiplied by the ratio of the attacking wizard's rank over the defending wizard's rank.

// The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.

using namespace std;

Wizard::Wizard(const string n, double hp, double atk, int r) :  Character(WIZARD, n, hp, atk)
{
    rank = r;
}
void Wizard::attack(Character &opponent)
{
    double dam = 0.0;
    if(opponent.getType() == WIZARD)
    {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        dam = this->attackStrength * static_cast<double>(this->rank) /opp.rank;
        opp.damage(dam);
    }
    else
    {
        dam = attackStrength;
        opponent.damage(dam);
    }
    cout << "Wizard " << this->getName() << " attacks " << opponent.getName() << " --- POOF!!"
         << endl << opponent.getName() << " takes " << dam << " damage." << endl;
}