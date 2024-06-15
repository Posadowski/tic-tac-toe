#include <iostream>
#include <vector>

#include "banner.h"
#include "gameMachinery.h"

int main()
{
    displayTicTacToe();
    std::vector<std::vector<char>> board(3, std::vector<char>(3, '_'));

    std::cout << "Enter whether you choose O or X ?" << std::endl;
    char selectedTeam;
    std::cin >> selectedTeam;

    while (!userSelectedTeamCorrectly(&selectedTeam))
    {
        std::cin >> selectedTeam;
    }

    displayRules();

    std::cout << selectedTeam << " is selected" << std::endl;

    bool gameFinished = false;
    char selectedRow, selectedCol;
    while (!gameFinished)
    {
        drawMap(board);

        std::cout << "Choose column" << std::endl;
        std::cin >> selectedCol;
        while (!userSelectedRowOrColumnCorrectly(selectedCol))
        {
            std::cin >> selectedCol;
        }
        std::cout << "Choose row" << std::endl;
        std::cin >> selectedRow;
        while (!userSelectedRowOrColumnCorrectly(selectedRow))
        {
            std::cin >> selectedRow;
        }
        // Adjust for 0-based indexing
        int selectedColInt = selectedCol - '1'; // 1 in ASCII is 49 so in exaple char '9' - '1' = 8 
        int selectedRowInt = selectedRow -'1';

        // Check if indices are within bounds
        if (selectedRowInt >= 0 && selectedRowInt < ROWS && selectedColInt >= 0 && selectedColInt < COLUMNS) {
            // Check if the cell is empty
            if (board[selectedRowInt][selectedColInt] == '_') {
                board[selectedRowInt][selectedColInt] = selectedTeam;
            } else {
                std::cout << "The cell is already occupied. Please choose another cell." << std::endl;
                continue; // Skip the rest of the loop and prompt the user again
            }
        } else {
            std::cout << "Selected row or column is out of bounds." << std::endl;
            continue; // Skip the rest of the loop and prompt the user again
        }

        // Optionally switch player team for next move
        gameFinished = checkIfGameFinished(board,selectedTeam);
        if(gameFinished){
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Cogratulations! " << selectedTeam << " wins" << std::endl;
            std::cout << " Game Finished " << std::endl;
        }
        selectedTeam = (selectedTeam == 'X') ? 'O' : 'X';
    }
    drawMap(board);
    return 0;
}