#include <stdio.h>
#include <ctype.h> 
#include <string.h> //Header files

typedef struct { //Tracking the scores of players
    int winsPlayer1;
    int winsPlayer2;
} Scoreboard;

Scoreboard scores = {0, 0};  // Tracking global scores

void showScores() { // Function to display the scores

    // Checking if no points have been accumulated yet
    if (scores.winsPlayer1 == 0 && scores.winsPlayer2 == 0) { 
        printf("No points have been accumulated yet, please start the game!\n");
    } else { 
        // Display the scores of Player 1 and Player 2
        printf("Player 1 Wins: %d\nPlayer 2 Wins: %d\n", scores.winsPlayer1, scores.winsPlayer2);
    }
}

// Function to display the instructions for playing the Hangman game
void displayInstructions() {
    // Display the instructions for the Hangman game
    printf("------------- INSTRUCTIONS -------------\n");
    printf("Hangman is a classic word-guessing game. The goal is to guess a hidden word by suggesting letters.\n");
    printf("The game is played with two players. One player (Player X) provides a word, and the other player (Player Y) tries to guess it.\n\n");

    printf("Game Play:\n");
    printf("1. Player X inputs a word, which Player Y tries to guess by suggesting letters.\n");
    printf("2. Player Y suggests a letter.\n");
    printf("3. If the letter is in the word, it is revealed in its correct position(s).\n");
    printf("4. If the letter is not in the word, one guess attempt is used, and the hangman graphic is updated.\n");
    printf("5. Player Y continues to guess letters until either the word is guessed or all guess attempts are used.\n\n");

    printf("Guess Attempts and the Hangman Graphic:\n");
    printf("Player Y has 6 guess attempts. With each incorrect guess, the hangman graphic progresses from an empty scaffold to a full hangman.\n");

    printf("\nScoring and Game End:\n");
    printf("1. If Player Y correctly guesses the word before all guess attempts are used, they win the game.\n");
    printf("2. If Player Y uses all guess attempts without guessing the word, Player X wins the game.\n");
    printf("3. Scores are tracked for both Player 1 and Player 2. The player who wins the round scores a point.\n\n");

    printf("To play again, select option (1) from the menu.\n");
    printf("To view scores, select option (3) from the menu.\n");
    printf("---------------------------------------------------\n\n");
}

// Function to display the main menu using the user's input
void menuFunction() {
    int option;

    // Display the main menu at least once and prompt user for input until they select option 1
    do {
        printf("\n------------- THE HANGMAN GAME -------------\n");
        printf("\nSelect an option:");
        printf("\n(1)\tStart Game\n(2)\tRules\n(3)\tScores\n\n");
        scanf("%d", &option);

        switch (option) {
        case 1:
            break;
        case 2:
            // Display the rules and instructions of the game
            displayInstructions();
            break;
        case 3:
            // Display the scores
            showScores();
            break;
        default:
            // Inform the user to select an available option if the input is invalid
            printf("Select an available option.\n\n");
        }
    } while (option != 1); // Loop until the user selects option 1 to start the game
}

// Function to display the hangman graphics based on the number of tries
void hangman(int numTries) {
    switch(numTries) {
        case 0: // Prints the hangman ASCII art for 0 tries
            printf("  ________\n");
            printf("  |/     |\n");
            printf("  |      |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf(" _|_\n");
            break;
        case 1: // Cases 1-5: Prints the hangman ASCII art for 1-5 tries with more complexity
            printf("  ________\n");
            printf("  |/     |\n");
            printf("  |      O\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf(" _|_\n");
            break;
        case 2:
            printf("  ________\n");
            printf("  |/     |\n");
            printf("  |      |\n");
            printf("  |      O\n");
            printf("  |      |\n");
            printf("  |\n");
            printf(" _|_\n");
            break;
        case 3:
            printf("  ________\n");
            printf("  |/     |\n");
            printf("  |      |\n");
            printf("  |      O\n");
            printf("  |     /|\n");
            printf("  |\n");
            printf(" _|_\n");
            break;
        case 4:
            printf("  ________\n");
            printf("  |/     |\n");
            printf("  |      |\n");
            printf("  |      O\n");
            printf("  |     /|\\\n");
            printf("  |\n");
            printf(" _|_\n");
            break;
        case 5:
            printf("  ________\n");
            printf("  |/     |\n");
            printf("  |      |\n");
            printf("  |      O\n");
            printf("  |     /|\\\n");
            printf("  |     /\n");
            printf(" _|_\n");
            printf("LAST TRY!"); // Prints "LAST TRY!" if it's the 5th try
            break;
        case 6:
            printf("  ________\n");
            printf("  |/     |\n");
            printf("  |      |\n");
            printf("  |      O\n");
            printf("  |     /|\\\n");
            printf("  |     / \\\n");
            printf(" _|_\n");
            break;
    }
}

/* Function to display the word with hidden characters replaced by underscores
 and the guessed letters */
void wordToGuess(char *word, char *hideWord) { 
    int i;
    int size = strlen(word);


    for (i = 0; i < size; i++) {
        if (hideWord[i] != '_') {
            printf("%c ", hideWord[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

// Main game function where players guess the word
void mainGame(int playerX, int playerY) {
    int wordSize, i;
    int tries = 0, maxTries = 6;
    char word[100];

    // Player inputs the word to be guessed
    printf("\nPlayer %d enter your word:\n", playerX);
    scanf("%s", word);
    wordSize = strlen(word);

    // Convert the word to lowercase for case-insensitive comparison
    for (i = 0; i < wordSize; i++) {
        word[i] = tolower(word[i]);
    }

// Initialize array to hide the word with underscores
    char hideWord[wordSize + 1];
    for (i = 0; i < wordSize; i++) {
        hideWord[i] = '_';
    }
    hideWord[wordSize] = '\0';

    // Display initial hangman state
    printf("\n\n");
    hangman(tries);
    printf("\n");
    wordToGuess(word, hideWord);
    printf("\n");

// Loop until maximum tries reached or word guessed
    while (tries < maxTries && strcmp(word, hideWord) != 0) {
        int letterFound = 0;
        char letterGuessed;

// Player guesses a letter
        printf("Player %d enter a letter:\n", playerY);
        scanf(" %c", &letterGuessed);
        letterGuessed = tolower(letterGuessed);

// Check if guessed letter is in the word
        for (i = 0; i < wordSize; i++) {
            if (word[i] == letterGuessed && hideWord[i] == '_') {
                hideWord[i] = letterGuessed;
                letterFound = 1;
            }
        }

// Incrementing tries if guessed letter not found in the word
        if (!letterFound) {
            tries++;
        }

// Display updated hangman state and the word with guessed letters revealed
        printf("\n\n");
        hangman(tries);
        printf("\n");
        wordToGuess(word, hideWord);
        printf("\n");
    }

 // Printing game outcome
    if (strcmp(word, hideWord) == 0) {

        // Player won
        printf("  ________\n");
        printf("  |/     |\n");
        printf("  |      |\n");
        printf("  |\n");
        printf("  |         \\O/\n");
        printf("  |          |\n");
        printf(" _|_        / \\\n");
        printf("\nYOU SAVED THE HANGED MAN\n");
        printf("\n-----------PLAYER %d WON!-----------\n", playerY);
        if (playerY == 1) {
            scores.winsPlayer1++;
        } else {
            scores.winsPlayer2++;
        }
    } else {
        // Player lost the game
        printf("\n-----------END OF THE GAME-----------\n");
        printf("The word was: %s\n", word);
    }
}

int main() {
    int playerX = 1, playerY = 2, game = 1, temp;

    menuFunction(); // Displays menu

    while (game == 1) {
        mainGame(playerX, playerY); // Main function of the game

        // Switch players for the next round
        temp = playerY;
        playerY = playerX;
        playerX = temp;

        // Prompt user to play again or view scores
        printf("\nDo you want to play again?\n(1) Yes\n(2) No\n(3) View Scores\n");
        scanf("%d", &game);

        // If user wants to view scores, display scores and prompt again for playing
        if (game == 3) {
            showScores();
            printf("\nDo you want to play again?\n(1) Yes\n(2) No\n");
            scanf("%d", &game);
        }

        while (game != 1 && game != 2 && game != 3) { // Validating user input
            printf("Invalid option, please type a valid option\n");
            scanf("%d", &game);
        }
    }

    // End of game message
    printf("\nThanks for playing!\n\n-----------------END-----------------\n");

    return 0;
}