#include <iostream>
using namespace std;

class Gladiator{
    private:
        string name;
        int health;
        int attackPower;
    public:
        Gladiator(string name_gladiator, int sethealth, int damagePower){
            
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

        int getHealth(){
            if (health < 0){
                return health = 0;
            }
            return health;
        }

        bool isalive(){
            return health > 0;
        }

        void attack(Gladiator* target){
            if (target == nullptr){
                return;
            }

            target->health -= attackPower;
        }
        void heal(){
            health += health + health / 10;
            if (health > 1000){
                cout << "Limit can't be passed. Max 1000 health" << endl;
                health = 1000;
            }
        }
        string getName() {
            return name;
        }
};

int main(){
    std::string player1_name = "Zeus";
    std::string player2_name = "Thanos";
    int player1_health = 100;
    int player2_health = 150;
    int player1_damage = 25;
    int player2_damage = 15;
    int choice = 0;
    int autoSet = 0;

    std::cout << "Automatic character creation? Press 1 to skip or press 2 to continue" << std::endl;
    std::cin >> autoSet;

    // SET NAME, HEALTH and DAMAGE
    if (autoSet == 2){
        // PLAYER 1
        std::cout << "Enter name for player 1" << std::endl;
        std::cin >> player1_name;
        std::cout << "Enter Health for player 1" << " (maximum 1.000)" << std::endl;
        std::cin >> player1_health;
        std::cout << "Enter damage power for player 1" << " (maximum 100)" << std::endl;
        std::cin >> player1_damage;
        // PLAYER 2
        std::cout << "Enter name for player 2" << std::endl;
        std::cin >> player2_name;
        std::cout << "Enter Health for player 2" << " (maximum 1.000)" << std::endl;
        std::cin >> player2_health;
        std::cout << "Enter damage power for player 2" << " (maximum 100)" << std::endl;
        std::cin >> player2_damage;
    }

    Gladiator* player1 = new Gladiator{player1_name, player1_health, player1_damage};
    Gladiator* player2 = new Gladiator{player2_name, player2_health, player2_damage};

    // Game Loop
    while (player1->isalive() and player2->isalive()) {
        std::cout << player1->getName() << " choose:" << std::endl;
        std::cout << "Enter 1 to Attack" << std::endl;
        std::cout << "Enter 2 to Wait" << std::endl;
        std::cin >> choice;

        if (choice == 1){
            player1->attack(player2);

            // Normally I could do player1_name and player2_name here.
            std::cout << player1->getName() << " hits " << player2->getName() << std::endl;  
            std::cout << player2->getName() << "'s HP: " << player2->getHealth() << std::endl;
            
            if (!player2->isalive()){
                std::cout << player1->getName() << " won" << std::endl;
                break;   
            }
        }
        else if (choice == 2){
            int before_healing_player1 = player1->getHealth();
            player1->heal();
            int after_healing_player1 = player1->getHealth();

            std::cout << player1->getName() << "'s HP increased by " << after_healing_player1 - before_healing_player1 << std::endl; 
            std::cout <<"New HP: "<< player1->getHealth() << std::endl;
        }
        else{
            std::cout << "You lost you chance to attack or heal" << std::endl;
        }

        // TURN 2
        
        std::cout << player2->getName() << " choose:" << std::endl;
        std::cout << "Enter 1 to Attack" << std::endl;
        std::cout << "Enter 2 to Wait" << std::endl;
        std::cin >> choice;

        if (choice == 1){
            player2->attack(player1);

            std::cout << player2->getName() << " hits " << player1->getName() << std::endl;  
            std::cout << player1->getName() << "'s HP: " << player1->getHealth() << std::endl;
            
            if (!player1->isalive()){
                std::cout << player2->getName() << " won" << std::endl;
                break;   
            }
        }
        else if (choice == 2){
            int before_healing_player2 = player2->getHealth();
            player2->heal();
            int after_healing_player2 = player2->getHealth();

            std::cout << player2->getName() << "'s HP increased by " << after_healing_player2 - before_healing_player2 << std::endl;
            std::cout <<"New HP: "<< player2->getHealth() << std::endl;
        }
        else{
            std::cout << "You lost you chance to attack or heal" << std::endl;
        }

    }

    delete player1;
    delete player2;
    return 0;
}