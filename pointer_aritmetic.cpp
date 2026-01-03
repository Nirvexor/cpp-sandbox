#include <iostream>
using namespace std;

int main() {
    // Task 4
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers; //Points the start. be careful because the size decays. So make it in a second variable.

    for (int i = 0; i < 5; i++){
        cout << *(ptr + i) << endl;
    }

    // Task
    cout << "Task place" << endl; // I'm doing this to differentiate the tasks.

    struct Enemy{
        int id;
        int hp;
    };
    Enemy enemy;
    Enemy* pEnemy = &enemy;
    pEnemy ->id = 1;
    pEnemy ->hp = 100;
    
    cout << pEnemy->id << endl;
    cout << pEnemy->hp << endl;

    Enemy* enemy2 = new Enemy;
    
    enemy2 ->id = 2;
    enemy2 ->hp = 100;

    cout << "Enemy 2 ID: "<< enemy2->id << endl;
    cout << "Enemy 2 HP: "<< enemy2->hp << endl;

    delete enemy2;

    return 0;
}