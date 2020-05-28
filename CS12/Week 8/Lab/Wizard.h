#include <string>
#include <iostream>
#include "Character.h"

#ifndef __WIZARD_H__
#define __WIZARD_H__

using namespace std;

class Wizard : public Character
{
    private:
        int rank;
    public:
        Wizard(const string, double, double, int);
        void attack(Character &);
};

#endif

