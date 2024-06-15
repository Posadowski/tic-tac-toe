
#include "gameMachinery.h"

void drawMap(const std::vector<std::vector<char>> &currentBoard)
{
    for (int row = 0; row < ROWS; ++row)
    {
        for (int col = 0; col < COLUMNS; ++col)
        {
            std::cout << " " << currentBoard[row][col] << " ";
            if (col < COLUMNS - 1)
            {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if (row < ROWS - 1)
        {
            std::cout << "-----------" << std::endl;
        }
    }
}

bool userSelectedTeamCorrectly(char *userInput)
{
    switch (*userInput){
        case 'x':
            *userInput = 'X';
            return true;
            break;
        case 'o':
            *userInput = 'O';
            return true;
            break;
        case 'X':
        case 'O':
            return true;
            break;
        default:
            std::cout << "[ERROR] Entered value is incorrect" << std::endl;
            std::cout << "Choose X or O" << std::endl;           
            return false;
    }
    return false;
}

bool userSelectedRowOrColumnCorrectly(char userInput)
{
    if (userInput >= '1' && userInput <= '3')
    {
        return true;
    }
    std::cout << "Select a number between 1 and 3" << std::endl;
    return false;
}

bool checkIfGameFinished(const std::vector<std::vector<char>> &currentBoard, char currentPlayer){
    
    // are O's or X's 3 in te same col?   
    for (int row = 0; row < ROWS; ++row)
    {
        if(currentBoard[row][0] == currentPlayer && currentBoard[row][1] == currentPlayer && currentBoard[row][2] == currentPlayer){
          return true;
        }
    }
    // are O's or X's 3 in te same row?   
    for (int col = 0; col < COLUMNS; ++col)
    {
        if(currentBoard[0][col] == currentPlayer && currentBoard[1][col] == currentPlayer && currentBoard[2][col] == currentPlayer){
          return true;
        }
    }

    if((currentBoard[0][0] == currentPlayer && currentBoard[1][1] == currentPlayer && currentBoard[2][2] == currentPlayer) || 
           (currentBoard[0][2] == currentPlayer && currentBoard[1][1] == currentPlayer && currentBoard[2][0] == currentPlayer)){
          return true;
    }

    return false;
}
