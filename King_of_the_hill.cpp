#include <iostream>
using namespace std;

int main() {
    // 1. Create the Array (fixed size of 5)
    int score[5] = {10, 25, 50, 75, 100};
    int index_of_the_highest_score = 0;
    int maxScore = score[0];

    // 2. Loop through the Array

    cout << "Reading Scores" << endl;
    
    for (int i = 1; i < 5; i++){
        if (score[i] > maxScore) {
            maxScore = score[i];
            index_of_the_highest_score = i;
        }
    }
    cout << "The highest score is "<< maxScore << " at index" << index_of_the_highest_score;

    return 0;
}