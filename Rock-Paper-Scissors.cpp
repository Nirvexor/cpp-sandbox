#include <iostream>
#include <random>


int getComputerChoice(){
    // Setup the "Device"
    std::random_device rd;

    // Setup the engine
    // Static can be used static to make it less expensive.
    static std::mt19937 gen(rd());

    // Define the Range (1 to 3, or 0 to 2)
    std::uniform_int_distribution<> distrib(1, 3);

    //Generate
    int computerChoice = distrib(gen);

    return computerChoice;
}

enum RPS{
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3
};

void determineWinner(int playerDecision, int computerDecision) {
    
    if (playerDecision == computerDecision){
        std::cout << "DRAW";
    }
    else if (computerDecision == ROCK and playerDecision == SCISSORS){
        std::cout << "Computer wins" << std::endl;
    }
    else if (playerDecision == ROCK and computerDecision == SCISSORS){
        std::cout << "Player wins"<< std::endl;
    }
    else if (computerDecision < playerDecision){
        std::cout << "Player wins";
    }
    else{ // playerDecision < computerDecision
        std::cout << "Computer Wins" << std::endl;
    }
}

int main() {
    int playerChoice = 0;
    int continue_choice = 1;

    while (true){
        
        // Get Player Choice
        std::cout << "Welcome to the Rock Paper Scissors" << std::endl;
        std::cout << "What is your choice ?" << std::endl;
        std::cout << "1. Rock, 2.Paper, 3. Scissors" << std::endl;
        std::cin >> playerChoice;

        // Get Computer Choice
        int computerValue = getComputerChoice();
        std::cout << "Computer chose: " << computerValue << std::endl;

        determineWinner (playerChoice, computerValue);

        // Restart
        std::cout << "Do you want to continue? (1 for yes and 2 for no)" << std::endl;
        std::cin >> continue_choice;
        if (continue_choice == 2){
            break;
        }
    }
    return 0;
}