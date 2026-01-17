#include <iostream>
using namespace std;

int main() {
    int score[5] = {10, 25, 50, 75, 100};
    bool isTheNumberFound = false;
    int target;
    cout << "Enter number to find: ";
    cin >> target;

    cout << "Reading Scores" << endl;
    
    for (int i = 0; i < 5; i++){
        if (score[i] == target) {
            cout << "Found "<< target << " at index" << i ;
            isTheNumberFound = true;
            break;
        }
    }
    if (isTheNumberFound == false){
        cout << "Error: Number not found." << endl;
    }

    return 0;
}