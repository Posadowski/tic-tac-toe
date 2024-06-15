#ifndef _GAME_MACHINERY_H
#define _GAME_MACHINERY_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#define COLUMNS 3
#define ROWS 3

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 600
#define CELL_SIZE 200
#define PADDING 5

#define UNCHECKED_BOX '_'

enum possible_match_results{
    MATCH_RESULT_UNKNOWN = 0,
    MATCH_RESULT_WIN = 1,
    MATCH_RESULT_DRAW = 2,
    MATCH_RESULT_MAX
};

void drawBoard(sf::RenderWindow& window, std::vector<std::vector<char>>& board,sf::Font& font);
void drawResult(sf::RenderWindow& window,sf::Font& font, char currentPlayer,possible_match_results gameResult);
bool userSelectedTeamCorrectly(char *userInput);
bool userSelectedRowOrColumnCorrectly(char userInput);
possible_match_results checkIfGameFinished(const std::vector<std::vector<char>> &currentBoard, char currentPlayer);

#endif // _GAME_MACHINERY_H