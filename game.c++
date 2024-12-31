#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype> // For tolower() function

using namespace std;

// Function to convert the input string to lowercase
string toLowerCase(string input) {
    for (char &c : input) {
        c = tolower(c); // Convert each character to lowercase
    }
    return input;
}

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
string determineWinner(string playerChoice, string aiChoice, int &playerWins, int &aiWins, int &ties) {
    if (playerChoice == aiChoice) { // If both choices are the same, it's a tie
        ties++;  // Increment tie count
        return "It's a tie!";  // Inform the player that it was a tie
    }
    // If the player wins according to the rules of Rock, Paper, Scissors
    if ((playerChoice == "Rock" && aiChoice == "Scissors") || 
        (playerChoice == "Scissors" && aiChoice == "Paper") || 
        (playerChoice == "Paper" && aiChoice == "Rock")) {
        playerWins++;  // Increment player win count
        return "You win!";  // Player wins
    } else {
        aiWins++;  // Increment AI win count
        return "You lose!"; // AI wins
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    string playAgain = "yes";  // Variable to control the replay loop

    // Variables to track the score
    int playerWins = 0, aiWins = 0, ties = 0;

    while (playAgain == "yes" || playAgain == "y") { // Loop to allow multiple rounds
        cout << "Welcome to Rock, Paper, Scissors!" << endl;
        cout << "Choose your move (Rock, Paper, Scissors): ";
        
        string playerChoice;
        cin >> playerChoice;  // Get the player's choice

        // Convert player input to lowercase to handle case insensitivity
        playerChoice = toLowerCase(playerChoice);

        // Validate the player's input
        if (playerChoice != "rock" && playerChoice != "paper" && playerChoice != "scissors") {
            // If the input is not Rock, Paper, or Scissors, prompt an error message
            cout << "Invalid choice! Please choose Rock, Paper, or Scissors." << endl;
            continue;  // Continue the loop to let the player try again
        }

        // Capitalize the player's input to match AI choice (Rock, Paper, Scissors)
        if (playerChoice == "rock") playerChoice = "Rock";
        if (playerChoice == "paper") playerChoice = "Paper";
        if (playerChoice == "scissors") playerChoice = "Scissors";

        cout << "You chose: " << playerChoice << endl; // Display the player's choice

        // Get the AI's choice
        string aiChoice = getAIChoice();
        cout << "AI chooses: " << aiChoice << endl; // Display the AI's choice

        // Determine and display the result of the game
        string result = determineWinner(playerChoice, aiChoice, playerWins, aiWins, ties);
        cout << result << endl; // Display whether the player won, lost, or tied

        // Display current score
        cout << "Score: You " << playerWins << " - AI " << aiWins << " - Ties " << ties << endl;

        // Ask the player if they want to play again
        cout << "Do you want to play again? (yes/no OR y/n): ";
        cin >> playAgain;  // Get the player's decision to play again
    }

    cout << "Thanks for playing Rock, Paper, Scissors!" << endl; // Final message when the player exits

    return 0;  // End the program
}
