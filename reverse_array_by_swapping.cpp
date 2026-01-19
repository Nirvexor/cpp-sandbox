#include <iostream>
using namespace std;

int main() {
    // 1. Create the Array (fixed size of 10)
    const int number = 10;
    int score[number] = {10, 25, 50, 75, 100, 42, 65, 74, 33, 89};
    int temp = 0;
    int counter = number - 1;
    // 2. Loop through the Array

    cout << "Reading Scores" << endl;
    for (int i = 0;i < 10; i++){
        cout << score[i] << " ";
    }
    cout << endl;

    // LOGIC
    for (int i = 0; i < 5; i++){
        temp = score[i];
        score[i] = score[counter];
        score[counter] = temp;
        counter--;
    }

    // Printing The Scores
    for (int i = 0; i < 10; i++){
        cout << score[i] << ", ";
    }

    return 0;
}