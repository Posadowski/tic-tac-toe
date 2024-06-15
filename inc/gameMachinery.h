#ifndef _GAME_MACHINERY_H
#define _GAME_MACHINERY_H

#include <iostream>
#include <vector>

#define COLUMNS 3
#define ROWS 3

void drawMap(const std::vector<std::vector<char>> &currentBoard);
bool userSelectedTeamCorrectly(char *userInput);
bool userSelectedRowOrColumnCorrectly(char userInput);
bool checkIfGameFinished(const std::vector<std::vector<char>> &currentBoard, char currentPlayer);

#endif // _GAME_MACHINERY_H