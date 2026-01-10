#include <iostream>
#include <random>

int random_int(int range){
    // Setup the "Device"
    std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, range);
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
    int lives = 10;
    bool isAlive = true;
    std::cout << "You have " << lives << " out of 10" << std::endl;
    
    int selected_number = random_int(difficultyLevel);

    while (isAlive){
        while (true) {
            std::cout << "Choose a number between 0 and " << difficultyLevel << std::endl;
            std::cout << "Guess the number: " << std::endl;
            std::cin >> guess_number;
            
            if (!(std::cin >> guess_number)) {
                // non-numeric input validation
                std::cout << "Invalid input. Try again!" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000000, '\n');
                continue;
            }

            if (guess_number >= 0 && guess_number <= difficultyLevel) {
                break;
            }

            std::cout << "Number is out of reach. Try again" << std::endl;
        }

        if (guess_number == selected_number){
            std::cout << "You win!" << std::endl;
            std::cout << "The selected number was " << selected_number << std::endl;
            std::cout << "You had " << lives << " lives while doing this" << std::endl;
            break; 
        }
        else if (guess_number > selected_number){
            std::cout << "Guess lower" << std::endl;
            lives--;
            std::cout << "You have " << lives << " out of 10" << std::endl;
        }
        else{ // guess_number < selected_number
            std::cout << "Guess higher" << std::endl;
            lives--;
            std::cout << "You have " << lives << " out of 10" << std::endl;
        }
        if (lives == 0){
            std::cout << "Game OVER" << std::endl;
            isAlive = false;
        }
    }
}

int main() {
    int again = 1;
    bool error_expected = true;
    std::cout << "Welcome to the Number Guessing Game" << std::endl;
    while (true){
        int selectDifficulty = 1;

        std::cout << "1. Novice (0 - 100)" << std::endl;
        std::cout << "2. Easy (0 - 1000)" << std::endl;
        std::cout << "3. Medium (0 - 10000)" << std::endl;
        std::cout << "4. Hard (0 - 100000)" << std::endl;
        std::cout << "Choose Difficulty:" << std::endl;

        // Input Validation
        while (error_expected) {
            if (!(std::cin >> selectDifficulty)){
                std::cout << "Invalid input. Try again (Enter numbers)" << std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
                continue;
            }

            if (selectDifficulty == NOVICE_LEVEL){
                error_expected = false;
                guess_number(NOVICE);
            }
            else if (selectDifficulty == EASY_LEVEL){
                error_expected = false;
                guess_number(EASY);
            }
            else if (selectDifficulty == MEDIUM_LEVEL){
                error_expected = false;
                guess_number(MEDIUM);
            }
            else if (selectDifficulty == HARD_LEVEL){
                error_expected = false;
                guess_number(HARD);
            }
            else{
                std::cout << "Invalid input. Try again (1,2,3,4)" << std::endl;
            }
        }

        // Restart
        std::cout << "Do you want to continue? (1 for yes and 2 for no)" << std::endl;
        std::cin >> again;
        if (again == 2){
            std::cout << "See you later" << std::endl;
            break;
        }
    }
    return 0;
}