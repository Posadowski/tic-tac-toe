#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "banner.h"
#include "gameMachinery.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic Tac Toe");

    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    }

    std::vector<std::vector<char>> board(3, std::vector<char>(3, '_'));
    char selectedTeam = 'X';
    bool gameFinished = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && !gameFinished) {
                int row = event.mouseButton.y / CELL_SIZE;
                int col = event.mouseButton.x / CELL_SIZE;
                if (row < 3 && col < 3 && board[row][col] == '_') {
                    board[row][col] = selectedTeam;
                    selectedTeam = (selectedTeam == 'X') ? 'O' : 'X';
                    gameFinished = checkIfGameFinished(board, selectedTeam);
                    if (gameFinished) {
                        std::cout << "Congratulations! " << selectedTeam << " wins" << std::endl;
                        window.close();
                    }
                }
            }
        }

        window.clear(sf::Color::White);
        drawBoard(window, board, font);
        window.display();
    }
}