# The-Hangman-Game

This is a simple Hangman game implemented in C, where two players take turns to guess letters of a hidden word. The game tracks wins for both players and allows them to view their scores. The game also includes visual feedback through a hangman graphic as players make incorrect guesses.

## Features
- **Two-player gameplay**: One player inputs a word, and the other guesses the letters.
- **Score tracking**: Scores are accumulated for both players, and can be viewed anytime.
- **Hangman graphics**: As the player makes incorrect guesses, a hangman figure is progressively drawn.
- **Game rules and instructions**: The program provides instructions on how to play the game.
- **Replay and score viewing**: After each round, players can choose to play again or view their scores.

## Compilation and Execution
To compile and run the program, use the following steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/vianneydb/The-Hangman-Game
   cd <repository_directory>
   ```

2. Compile in terminal:
   ```bash
   gcc hangman.c -o hangman
   ```

3. Run the program:
   ```bash
   ./hangman
   ```

## Game Play
1. Player X inputs a word that Player Y will try to guess.
2. Player Y guesses a letter, and the game will either reveal the letter's position or increment the number of incorrect guesses (up to 6 tries).
3. The game continues until Player Y either guesses the word correctly or uses all attempts.

## Example
Here is an example of the interaction:
```yaml
  ________
  |/     |
  |      O
  |     /|
  |
 _|_

_ _ _ _
Player 2 enter a letter:
|
```


## Contributing
If you want to contribute to this project, feel free to fork the repository, make your changes, and submit a pull request.


**Author**: Vianney Diaz.

**Date**: November 2024.
