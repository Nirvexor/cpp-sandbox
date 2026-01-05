#ifndef GLADIATOR_H
#define GLADIATOR_H

#include <iostream>
#include <string>

class Gladiator{
    private:
        std::string name;
        int health;
        int attackPower;
    public:
        // Constructor Declaration
        Gladiator(std::string name_gladiator, int sethealth, int damagePower);

        // Getter Declaration
        int getHealth();

        bool isalive();

        void attack(Gladiator* target);

        void heal();

        std::string getName();
};

#endif