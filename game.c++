#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> // For transform function

using namespace std;

// Function to generate AI's choice randomly
string getAIChoice() {
    int randomChoice = rand() % 3;
    switch (randomChoice) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: return ""; // Fallback (shouldn't occur)
    }
}

// Function to determine the winner between player and AI
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

// Function to display game rules
void displayRules() {
    cout << "\n--- Game Rules ---" << endl;
    cout << "1. Rock beats Scissors" << endl;
    cout << "2. Scissors beats Paper" << endl;
    cout << "3. Paper beats Rock" << endl;
    cout << "4. Enter 'Rock', 'Paper', or 'Scissors' to play." << endl;
}

// Function to implement "Best of X Rounds" gameplay
void playBestOfXRounds() {
    int rounds;
    cout << "\nHow many rounds would you like to play? ";
    cin >> rounds;

    int playerScore = 0, aiScore = 0; // Initialize scores

    for (int i = 1; i <= rounds; i++) {
        string playerChoice, aiChoice;
        cout << "\nRound " << i << " - Enter your move (Rock, Paper, Scissors): ";
        cin >> playerChoice;

        // Normalize player input to uppercase for consistency
        transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), ::toupper);

        // Convert normalized input back to proper casing
        if (playerChoice == "ROCK") playerChoice = "Rock";
        else if (playerChoice == "PAPER") playerChoice = "Paper";
        else if (playerChoice == "SCISSORS") playerChoice = "Scissors";
        else {
            cout << "Invalid choice! Skipping this round." << endl;
            continue;
        }

        aiChoice = getAIChoice(); // Generate AI's move
        cout << "AI chooses: " << aiChoice << endl;

        string result = determineWinner(playerChoice, aiChoice);
        cout << result << endl;

        // Update scores based on the result
        if (result == "You win!") playerScore++;
        else if (result == "You lose!") aiScore++;

        cout << "Score: You " << playerScore << " - " << aiScore << " AI" << endl;
    }

    // Display final results after all rounds
    cout << "\n--- Final Results ---" << endl;
    if (playerScore > aiScore) {
        cout << "Congratulations! You won the best of " << rounds << " rounds!" << endl;
    } else if (playerScore < aiScore) {
        cout << "AI wins the best of " << rounds << " rounds. Better luck next time!" << endl;
    } else {
        cout << "It's a tie!" << endl;
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
        cin >> choice; // Get the user's menu choice

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
            cout << "Invalid choice! Please enter a valid menu option." << endl;
        }
    }

    return 0;
}
