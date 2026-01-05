#include <iostream>
#include <limits> // For guarantee.
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

    // Input validation
    while (!(cin >> size)){
        cout << "Invalid input. Try again" << endl;
        cin.clear(); // Reset input errors. Removes error flags.
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards bad input. Skips the whole line or until it finds a '\n'
    }
    
    // Checking for invalid input
    if (size < 0){
        cout << "Invalid input, enemy size must be at least 1" << endl;
    }
    else if(size == 0){ // Actually just could have done size <= 0 for the condition but why not do it. Enjoy it a little
        cout << "I guess you don't want to see anything" << endl;
        return 0;
    }

    // Creating the dynamic array. Because we don't know how much enemy user will want to spawn.
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

    // Delete it and point to nothing after you have done.
    delete[] arr;
    arr = nullptr; //Practice this
    
    return 0;
}