
#include "gameMachinery.h"

[[deprecated]]
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

void drawBoard(sf::RenderWindow& window, std::vector<std::vector<char>>& board,sf::Font& font) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 2 * PADDING, CELL_SIZE - 2 * PADDING));
            cell.setPosition(i * CELL_SIZE + PADDING, j * CELL_SIZE + PADDING);
            cell.setOutlineThickness(PADDING);
            cell.setOutlineColor(sf::Color::Black);
            cell.setFillColor(sf::Color::White);
            window.draw(cell);

            if (board[j][i] != UNCHECKED_BOX) {
                sf::Text text(std::string(1, board[j][i]), font, 100);
                text.setFillColor(sf::Color::Black);
                text.setPosition(i * CELL_SIZE + 50, j * CELL_SIZE + 30);
                window.draw(text);
            }
        }
    }
}

void drawResult(sf::RenderWindow& window,sf::Font& font, char currentPlayer,possible_match_results gameResult){
    std::string windowString;
    switch (gameResult){
        case MATCH_RESULT_WIN:
            windowString = "Congratulations! WIN: " + std::string(1, currentPlayer);;

            break;
        case MATCH_RESULT_DRAW:
            windowString = "DRAW";
            break;
        default:
            std::cerr << "Unexpected match result " << std::endl;
            break;       
    }
    
    bool KeyPressed = false;
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Close the window properly
            } else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
                KeyPressed = true;
                break;
            }
        }
        if(KeyPressed){
            break;
        }
        // Clear, draw, and display
        window.clear(sf::Color::White);
        sf::Text windowText(windowString, font, 50);
        windowText.setFillColor(sf::Color::Black);
        // Center the text
        sf::FloatRect textRect = windowText.getLocalBounds();
        windowText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        windowText.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
        window.draw(windowText);
        window.display();
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

possible_match_results checkIfGameFinished(const std::vector<std::vector<char>> &currentBoard, char currentPlayer){

    // check if in vector are correct values
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(currentBoard[i][j] != UNCHECKED_BOX && currentBoard[i][j] != 'O' && currentBoard[i][j] != 'X'){  
               std::cerr << "Incorrect values in board vector " << currentBoard[i][j] << std::endl;
               return MATCH_RESULT_IMPOSSIBLE;
            }
        }
    }

    
    // are O's or X's 3 in te same col?   
    for (int row = 0; row < ROWS; ++row)
    {
        if(currentBoard[row][0] == currentPlayer && currentBoard[row][1] == currentPlayer && currentBoard[row][2] == currentPlayer){
          return MATCH_RESULT_WIN;
        }
    }
    // are O's or X's 3 in te same row?   
    for (int col = 0; col < COLUMNS; ++col)
    {
        if(currentBoard[0][col] == currentPlayer && currentBoard[1][col] == currentPlayer && currentBoard[2][col] == currentPlayer){
          return MATCH_RESULT_WIN;
        }
    }
    // are O's or X's  3 diagonally
    if((currentBoard[0][0] == currentPlayer && currentBoard[1][1] == currentPlayer && currentBoard[2][2] == currentPlayer) || 
           (currentBoard[0][2] == currentPlayer && currentBoard[1][1] == currentPlayer && currentBoard[2][0] == currentPlayer)){
          return MATCH_RESULT_WIN;
    }

    // Check if all boxes have been filled without selecting a winner
    int checkedBoxs = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(currentBoard[i][j] != UNCHECKED_BOX){
                checkedBoxs++;
            }
        }
    }
    if(checkedBoxs >= COLUMNS * ROWS){
        return MATCH_RESULT_DRAW;
    }

    return MATCH_RESULT_UNKNOWN;
}
