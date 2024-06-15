#include "banner.h"
#include <iostream>

void displayRules()
{

    std::string rules = R"(
Tic Tac Toe - Rules
1. The Tic Tac Toe game is intended for two players.
2. The board consists of 3 rows and 3 columns, forming a 3x3 grid.
3. One player uses the 'X' symbol and the other uses the 'O' symbol.
4. Players take turns placing their symbols in empty spaces on the board.
5. The first player to place three of their symbols in a horizontal, vertical or diagonal line wins the game.
6. If all spaces on the board are filled and no player places three symbols in a line, the game ends in a draw.

Instructions:
- To place your symbol, enter a row and column number, e.g. 1 1 for the top left corner.
- The game starts with player 'X'.
- Good luck and have fun!

Sample board:
 1  | 2  | 3
--------------
 4  | 5  | 6
--------------
 7  | 8  | 9
)";

    std::cout << rules << std::endl;
}


void displayTicTacToe(){
    std::string ticTacToe = R"(
  _____  _____  _  _           _____  _____  _  _            _____  _____  _____ 
 |_   _||_   _|| |/ /         |_   _||  _  || |/ /          |_   _||  _  ||_ ___|
   | |    | |  | . /   ______   | |  | |_| || . /   ______    | |  | | | || |___
   | |    | |  |  <   |______|  | |  |     ||  <   |______|   | |  | | | || ____|  
   | |   _| |_ | .  \           | |  |  _  || .  \            | |  | |_| || |___
   |_|  |_____||_| \_\          |_|  |_| |_||_| \_\           |_|  |_____||_____|
)";

  std::cout << ticTacToe << std::endl;
}