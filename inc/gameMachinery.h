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

void drawBoard(sf::RenderWindow& window, std::vector<std::vector<char>>& board,sf::Font& font);
bool userSelectedTeamCorrectly(char *userInput);
bool userSelectedRowOrColumnCorrectly(char userInput);
bool checkIfGameFinished(const std::vector<std::vector<char>> &currentBoard, char currentPlayer);

#endif // _GAME_MACHINERY_H