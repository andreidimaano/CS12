#include <string>
#include "Character.h"

#ifndef __ELF_H__
#define __ELF_H__

using namespace std;

class Elf : public Character
{
    private:
        string famName;
    public:
        Elf(const string &, double, double, string);
        void attack(Character &);
};

// Stores the elf's family name as a string.

// The elf does not attack elf's from its own family.

// The damage done by the elf is the percentage of the elf's health remaining (health / MAX_HEALTH) multiplied by the elf's attack strength.
#endif

