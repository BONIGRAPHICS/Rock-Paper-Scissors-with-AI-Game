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

// Function to display the rules
void displayRules() {
    cout << "\n--- Rules of Rock, Paper, Scissors ---" << endl;
    cout << "1. Rock beats Scissors." << endl;
    cout << "2. Scissors beats Paper." << endl;
    cout << "3. Paper beats Rock." << endl;
    cout << "4. If both choices are the same, it's a tie." << endl;
    cout << "---------------------------------------\n" << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    string playAgain = "yes";  // Variable to control the replay loop
    int choice; // Variable to store the menu choice

    // Variables to track the score
    int playerWins = 0, aiWins = 0, ties = 0;

    // Display the main menu
    while (true) {
        cout << "\n--- Rock, Paper, Scissors ---" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. View Rules" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Reset Scores" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Start the game
            while (playAgain == "yes" || playAgain == "y") { // Loop to allow multiple rounds
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
                cout << "Do you want to play again? (yes/no): ";
                cin >> playAgain;  // Get the player's decision to play again
            }

        } else if (choice == 2) {
            // Display the rules
            displayRules();

        } else if (choice == 3) {
            // Exit the program
            cout << "Thanks for playing Rock, Paper, Scissors!" << endl;
            break;

        } else if (choice == 4) {
            // Reset the scores
            playerWins = 0;
            aiWins = 0;
            ties = 0;
            cout << "\nScores have been reset!" << endl;
        } else {
            // Handle invalid menu choices
            cout << "Invalid choice! Please select 1, 2, 3, or 4." << endl;
        }
    }

    // Display the game summary
    int totalRounds = playerWins + aiWins + ties; // Calculate total rounds played
    cout << "\n--- Game Summary ---" << endl;
    cout << "Total rounds played: " << totalRounds << endl;
    cout << "You won: " << playerWins << " times" << endl;
    cout << "AI won: " << aiWins << " times" << endl;
    cout << "Ties: " << ties << endl;

    return 0; 
}
