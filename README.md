#  Tic-Tac-Toe 
## Overview
This project implements a console-based Tic-Tac-Toe game in C++. The game allows two players to take turns marking spaces on a 3x3 grid until one player wins by getting three of their marks in a row, column, or diagonal, or the game ends in a draw if the grid is full with no winner.

## Prerequisites

1. Computer with Linux installed (tested on Debian)
2. Necessary packages installed
```
sudo apt-get install g++ libgtest-dev libsfml-dev
```


## Key Features
1. Game Mechanics: Players alternate turns, marking 'X' or 'O' on the board.
2. Board Visualization: The current state of the board is displayed after each move, showing positions and moves made.
3. Input Validation: Ensures that player inputs are validated to prevent invalid moves or errors.
4. Win Condition Check: Automatically checks after each move if a player has won or if the game has ended in a draw.
5. Error Handling: Provides feedback for invalid inputs and prompts users to re-enter correct inputs.
6. Modularity: Code is structured into functions for clarity and maintainability.
7. Unit Tests: Includes unit tests using Google Test framework to verify core functionalities like input validation and win condition checking.
## Components
* Main Program (main.cpp): Entry point that manages game flow and user interactions.
* Game Mechanics (gameMachinery.cpp, gameMachinery.h): Implements functions for checking win conditions, handling player turns, and managing the game state.
* User Interface (banner.cpp, banner.h): Provides functions for displaying the messages to the console.
* Testing (test.cpp): Contains unit tests using Google Test framework to verify correctness of game logic functions.
## Build Instructions
* Compilation: Uses g++ compiler with C++11 standard and necessary flags (-Wall, -Wextra).
* Dependencies: Requires Google Test framework for unit testing (-lgtest, -lgtest_main, -pthread).
* Makefile: Includes targets for building the main game executable, running tests, and cleaning up generated files.
## Usage
1. Building: Run make to build the main game executable (bin/tic-tac-toe).
2. Testing: Run make test to compile and execute unit tests to ensure game functionalities are working correctly.
3. Playing: Execute bin/tic-tac-toe to start the game, follow on-screen instructions to play.
## Conclusion
This project demonstrates fundamental concepts of C++ programming including arrays, functions, control structures, input/output operations, and basic game logic. It provides an interactive and engaging implementation of the classic Tic-Tac-Toe game suitable for console-based environments.

