#include <iostream>
using namespace std;

class Enemy{
    protected:
        int health;
        int* weaponDamage;

    public:
        Enemy (int setHealth) {
            weaponDamage = new int;

            health = setHealth;

            *weaponDamage = 10;

            cout << "Enemy Spawned" << endl;
        }
        
        virtual ~Enemy() {
            cout << "Enemy Destroyed" << endl;
            delete weaponDamage;
        }
        
        virtual void attack(){
            cout << "Attacking for " << *weaponDamage << " damage" << endl;
        }
};
class Boss : public Enemy {
    public:
        Boss(int hp) : Enemy(hp){
            *weaponDamage = 30;
            cout << "Boss spawned, Good Luck" << endl;
        }
        void attack() override{
            cout << "BOSS COMING for " << *weaponDamage << endl;
        }
};

int main() {

    Enemy* dangerousEntitiy;
    dangerousEntitiy = new Boss(1000);
    dangerousEntitiy ->attack();
    delete dangerousEntitiy;
    dangerousEntitiy = nullptr;
    return 0;
}