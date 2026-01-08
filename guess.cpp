#include <iostream>
#include <random>

int random_int(int range){
    // Setup the "Device"
    std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, range);
    int computerSelection = distrib(gen);

    return computerSelection;
}

enum difficulty{
    NOVICE_LEVEL = 1,
    EASY_LEVEL = 2,
    MEDIUM_LEVEL = 3,
    HARD_LEVEL = 4
};
enum range{
    NOVICE = 100,
    EASY = 1000,
    MEDIUM = 10000,
    HARD = 100000
};

void guess_number(int difficultyLevel){
    int guess_number = 0;
    int selected_number = random_int(difficultyLevel);

    while (true){
        std::cout << "Guess the number: " << std::endl;
        std::cin >> guess_number;

        if (guess_number == selected_number){
            std::cout << "You win!" << std::endl;
            std::cout << "The selected number was " << selected_number << std::endl;
            break; 
        }
        else if (guess_number > selected_number){
            std::cout << "Guess lower" << std::endl;
        }
        else{ // guess_number < selected_number
            std::cout << "Guess higher" << std::endl;
        }
    }
}

int main() {
    int again = 1;
    std::cout << "Welcome to the Number Guessing Game" << std::endl;
    while (true){
        int selectDifficulty = 1;

        std::cout << "1. Novice" << std::endl;
        std::cout << "2. Easy" << std::endl;
        std::cout << "3. Medium" << std::endl;
        std::cout << "4. Hard" << std::endl;
        std::cout << "Choose Difficulty:" << std::endl;
        std::cin >> selectDifficulty;

        if (selectDifficulty == NOVICE_LEVEL){
            guess_number(NOVICE);
        }
        else if (selectDifficulty == EASY_LEVEL){
            guess_number(EASY);
        }
        else if (selectDifficulty == MEDIUM_LEVEL){
            guess_number(MEDIUM);
        }
        else{
            guess_number(HARD);
        }

        // Restart
        std::cout << "Do you want to continue? (1 for yes and 2 for no)" << std::endl;
        std::cin >> again;
        if (again == 2){
            break;
        }
    }
    return 0;
}