#include <string>
#include <iostream>
#include "Elf.h"

using namespace std;

Elf::Elf(const string &n, double hp, double atk, string f):  Character(ELF, n, hp, atk)
{
    famName = f;
}
void Elf::attack(Character &opponent)
{
    double dam = 0.0;
    if(opponent.getType()== ELF)
    {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(this->famName == opp.famName)
        {
            cout << "Elf " << this->getName() << " does not attack " << "Elf " << opponent.getName() << "." << endl
                 << "They are both members of the " << famName << " family." << endl;
            return;
        }
    }
        dam = ((this->health / MAX_HEALTH) * this->attackStrength);
        opponent.damage(dam);
        cout << "Elf " << this->getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl
             << opponent.getName() << " takes " << dam << " damage." << endl;
}


// Stores the elf's family name as a string.

// The elf does not attack elf's from its own family.

// The damage done by the elf is the percentage of the elf's health remaining (health / MAX_HEALTH) multiplied by the elf's attack strength.


