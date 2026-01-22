#ifndef GLADIATOR_H
#define GLADIATOR_H

#include <iostream>
#include <string>

class Gladiator{
    private:
        std::string name;
        int health;
        int attackPower;
        const int cheatHealth = 24;
        const int cheatattackPower = 72;
    public:
        // Constructor Declaration
        Gladiator(std::string name_gladiator, int sethealth, int damagePower);

        // Getter Declaration
        int getHealth();

        bool isalive();

        void attack(Gladiator* target);

        void heal();

        std::string getName();

        // TODO: Implement Resistance based on luck and part of health with a formula.
        // Suggestion: Take example of 'fun' value from Undertale and decide luck and resistance's luck part based on this value.
        // New skills to implement

        // This will simply get your resistance against damages.
        void resistance_potion(){};

        // This mechanich will be based on your luck, Luck will be determined by luck xD
        // Gamble will increase or decrease your damage based on Luck
        void gamble(){};
};

#endif