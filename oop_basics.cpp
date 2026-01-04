#include <iostream>
using namespace std;

class Enemy{
    private:
        int health;
        int* weaponDamage;

    public:
        Enemy (int setHealth) {
            weaponDamage = new int;

            health = setHealth;

            *weaponDamage = 10;

            cout << "Enemy Spawned" << endl;
        }
        
        ~Enemy() {
            cout << "Enemy Destroyed" << endl;
            delete weaponDamage;
        }
        
        void attack(){
            cout << "Attacking for " << *weaponDamage << " damage" << endl;
        }
};


int main() {
    cout << "Start of Main" << endl;
    {Enemy skeleton(200);
    skeleton.attack();} // Destructor's condition is curly braces.
    cout << "End of Main" << endl;
    
    Enemy slime(80);
    slime.attack();

    return 0;
}