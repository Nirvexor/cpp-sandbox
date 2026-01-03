#include <iostream>
using namespace std;

int main() {
    int Health = 100;
    int* pHealth = &Health;
    *pHealth = 80;

    cout << Health << endl;
    
    // New practice
    int* pScore = new int;
    *pScore = 500;
    
    cout << *pScore << endl;

    delete pScore;
    pScore = nullptr; //it points to nothing(0). Good practice, Don't forget this.

    // Task
    int size = 0;
    cout << "How many enemies you want to spawn?" << endl;
    cin >> size;
    int* arr = new int[size]; // don't put it before the input
    for (int i = 0; i < size; i++){
        int number = 0;
        cout << "What is the health of the enemy"<< endl;
        cin >> number;
        arr[i] = number;

    }

    for (int i = 0; i < size; i++){
        cout << "Health of the enemy: " << arr[i] << endl;
    }

    delete[] arr;
    arr = nullptr; //Practice this
    
    return 0;
}