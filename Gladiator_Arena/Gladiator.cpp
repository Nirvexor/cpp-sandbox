#include "Gladiator.h"



Gladiator::Gladiator(std::string name_gladiator, int sethealth, int damagePower){

    name = name_gladiator;
            
    if (sethealth > 1000){
        health = 1000;
    }
    else if (sethealth == 24){
        health = 10000;
    }
    else if (sethealth < 30){
        health = 30;
    }
    else{
        health = sethealth;
    }
            

    if (damagePower > 100){
        attackPower = 100;
    }
    else if (damagePower < 15){
        attackPower = 15;
    }
    else if (damagePower == 72){
        attackPower = 1000;
    }
    else{
        attackPower = damagePower;
    }
}
int Gladiator::getHealth(){
    if (health < 0){
        return health = 0;
    }
    return health;
}

bool Gladiator::isalive(){
    return health > 0;
}

void Gladiator::attack(Gladiator* target){
    if (target == nullptr){
        return;
    }

    target->health -= attackPower;
}

void Gladiator::heal(){
    health += health / 10;
    if (health > 1000){
        std::cout << "Limit can't be passed. Max 1000 health" << std::endl;
        health = 1000;
    }
}

std::string Gladiator::getName() {
    return name;
}