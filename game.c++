#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to get AI's choice
string getAIChoice() {
    int randomChoice = rand() % 3;
    switch (randomChoice) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: return "";
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Welcome message
    cout << "Welcome to Rock, Paper, Scissors!" << endl;

    // Ask the player for their choice
    cout << "Choose your move (Rock, Paper, Scissors): ";
    string playerChoice;
    cin >> playerChoice;

    // Validate the player's choice
    if (playerChoice != "Rock" && playerChoice != "Paper" && playerChoice != "Scissors") {
        cout << "Invalid choice! Please choose Rock, Paper, or Scissors." << endl;
        return 1;
    }

    // Display the player's choice
    cout << "You chose: " << playerChoice << endl;

    // Get and display the AI's choice
    string aiChoice = getAIChoice();
    cout << "AI chooses: " << aiChoice << endl;

    return 0;
}