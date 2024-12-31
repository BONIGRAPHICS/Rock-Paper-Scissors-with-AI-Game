#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to get the AI's random choice: Rock, Paper, or Scissors
string getAIChoice() {
    int randomChoice = rand() % 3;  // Generate a random number between 0 and 2
    switch(randomChoice) {
        case 0: return "Rock";     // If 0, AI chooses Rock
        case 1: return "Paper";    // If 1, AI chooses Paper
        case 2: return "Scissors"; // If 2, AI chooses Scissors
        default: return "";        // Default case, although this shouldn't happen
    }
}

// Function to determine the winner based on the player's and AI's choices
string determineWinner(string playerChoice, string aiChoice) {
    if (playerChoice == aiChoice) { // If both choices are the same, it's a tie
        return "It's a tie!";
    }
    // If the player wins according to the rules of Rock, Paper, Scissors
    if ((playerChoice == "Rock" && aiChoice == "Scissors") || 
        (playerChoice == "Scissors" && aiChoice == "Paper") || 
        (playerChoice == "Paper" && aiChoice == "Rock")) {
        return "You win!";  // Player wins
    } else {
        return "You lose!"; // AI wins
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Choose your move (Rock, Paper, Scissors): ";
    
    string playerChoice;
    cin >> playerChoice;  // Get the player's choice

    // Validate the player's input
    if (playerChoice != "Rock" && playerChoice != "Paper" && playerChoice != "Scissors") {
        // If the input is not Rock, Paper, or Scissors, prompt an error message
        cout << "Invalid choice! Please choose Rock, Paper, or Scissors." << endl;
        return 1;  // Exit the program with an error code
    }

    cout << "You chose: " << playerChoice << endl; // Display the player's choice

    // Get the AI's choice
    string aiChoice = getAIChoice();
    cout << "AI chooses: " << aiChoice << endl; // Display the AI's choice

    // Determine and display the result of the game
    string result = determineWinner(playerChoice, aiChoice);
    cout << result << endl; // Display whether the player won, lost, or tied

    return 0; 
}
