#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string getAIChoice() {
    int randomChoice = rand() % 3;
    switch(randomChoice) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: return "";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Choose your move (Rock, Paper, Scissors): ";
    
    string playerChoice;
    cin >> playerChoice;

    cout << "You chose: " << playerChoice << endl;

    string aiChoice = getAIChoice();
    cout << "AI chooses: " << aiChoice << endl;

    return 0;
}
