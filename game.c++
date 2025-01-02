#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> // For transform function
#include <limits>    // For clearing invalid input

using namespace std;

// Function to randomly choose AI's move
string getAIChoice() {
    int randomChoice = rand() % 3;
    switch(randomChoice) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: return "";
    }
}

// Function to determine the winner of the game
string determineWinner(string playerChoice, string aiChoice) {
    if (playerChoice == aiChoice) {
        return "It's a tie!";
    }
    if ((playerChoice == "Rock" && aiChoice == "Scissors") || 
        (playerChoice == "Scissors" && aiChoice == "Paper") || 
        (playerChoice == "Paper" && aiChoice == "Rock")) {
        return "You win!";
    } else {
        return "You lose!";
    }
}

// Function to display the rules of the game
void displayRules() {
    cout << "\n--- Game Rules ---" << endl;
    cout << "1. Rock beats Scissors" << endl;
    cout << "2. Scissors beats Paper" << endl;
    cout << "3. Paper beats Rock" << endl;
    cout << "4. Choose your move: Rock, Paper, or Scissors" << endl;
}

// Function to play best of X rounds
void playBestOfXRounds() {
    int rounds;
    cout << "\nEnter the number of rounds for Best of X: ";
    cin >> rounds;

    int playerWins = 0, aiWins = 0, ties = 0;

    for (int i = 0; i < rounds; i++) {
        string playerChoice, aiChoice;
        cout << "\nRound " << i + 1 << ": Enter your move (Rock, Paper, Scissors): ";
        cin >> playerChoice;

        // Normalize player input to uppercase for consistency
        transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), ::toupper);

        // Convert normalized input back to proper casing
        if (playerChoice == "ROCK") playerChoice = "Rock";
        else if (playerChoice == "PAPER") playerChoice = "Paper";
        else if (playerChoice == "SCISSORS") playerChoice = "Scissors";
        else {
            cout << "Invalid choice! Skipping round." << endl;
            continue;
        }

        aiChoice = getAIChoice(); // Generate AI's move
        cout << "AI chooses: " << aiChoice << endl;

        string result = determineWinner(playerChoice, aiChoice);
        cout << result << endl;

        if (result == "You win!") playerWins++;
        else if (result == "You lose!") aiWins++;
        else ties++;
    }

    cout << "\n--- Final Score ---" << endl;
    cout << "Player Wins: " << playerWins << endl;
    cout << "AI Wins: " << aiWins << endl;
    cout << "Ties: " << ties << endl;
    
    if (playerWins > aiWins) {
        cout << "You win the Best of " << rounds << "!" << endl;
    } else if (aiWins > playerWins) {
        cout << "AI wins the Best of " << rounds << "!" << endl;
    } else {
        cout << "It's a tie in the Best of " << rounds << "!" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    while (true) { // Main menu loop
        // Display the main menu
        cout << "\n--- Rock, Paper, Scissors ---" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. View Rules" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Reset Scores" << endl;
        cout << "5. Play Best of X Rounds" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        // Check for invalid input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input! Please enter a number between 1 and 5." << endl;
            continue;
        }

        // Process the user's menu choice
        if (choice == 1) {
            // Single round gameplay
            string playerChoice, aiChoice;
            cout << "\nEnter your move (Rock, Paper, Scissors): ";
            cin >> playerChoice;

            // Normalize player input to uppercase for consistency
            transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), ::toupper);

            // Convert normalized input back to proper casing
            if (playerChoice == "ROCK") playerChoice = "Rock";
            else if (playerChoice == "PAPER") playerChoice = "Paper";
            else if (playerChoice == "SCISSORS") playerChoice = "Scissors";
            else {
                cout << "Invalid choice! Returning to main menu." << endl;
                continue;
            }

            aiChoice = getAIChoice(); // Generate AI's move
            cout << "AI chooses: " << aiChoice << endl;

            string result = determineWinner(playerChoice, aiChoice);
            cout << result << endl;

        } else if (choice == 2) {
            displayRules(); // Show game rules
        } else if (choice == 3) {
            // Exit the game
            cout << "Exiting the game. Goodbye!" << endl;
            break;
        } else if (choice == 4) {
            // Reset scores (placeholder - no actual score tracking here)
            cout << "Scores reset to 0!" << endl;
        } else if (choice == 5) {
            playBestOfXRounds(); // Call "Best of X Rounds" mode
        } else {
            // Handle invalid menu choices
            cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    }

    return 0;
}
