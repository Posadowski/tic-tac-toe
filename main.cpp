#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "banner.h"
#include "gameMachinery.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tic Tac Toe");

    // Load the font
    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    }

    // Load the logo image
    sf::Texture logoTexture;
    if (!logoTexture.loadFromFile("img/logo.jpg")) {
        std::cerr << "Failed to load logo image" << std::endl;
        return -1;
    }

    // Create a sprite for the logo
    sf::Sprite logoSprite;
    logoSprite.setTexture(logoTexture);

    // Adjust the size and position of the logo if necessary
    sf::Vector2u textureSize = logoTexture.getSize();
    logoSprite.setScale(WINDOW_WIDTH / float(textureSize.x), (WINDOW_HEIGHT / 2) / float(textureSize.y));
    logoSprite.setPosition(0, 0); // Center the logo at the top of the window

    // Create "Start Game" text
    sf::Text startText("Start Game", font, 50);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition((WINDOW_WIDTH - startText.getLocalBounds().width) / 2, 400);

    bool gameStarted = false;
    bool startButtonClicked = false; // New state to handle the start button click

    // Initial game board
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

            if (event.type == sf::Event::MouseButtonPressed && !gameStarted) {
                // Check if the "Start Game" text is clicked
                sf::FloatRect bounds = startText.getGlobalBounds();
                if (bounds.contains(event.mouseButton.x, event.mouseButton.y)) {
                    gameStarted = true;
                    startButtonClicked = true; // Set the flag to ignore the first mouse press after starting the game
                }
            }

            if (event.type == sf::Event::MouseButtonPressed && gameStarted && !gameFinished) {
                if (startButtonClicked) {
                    // Ignore the first mouse press after clicking "Start Game"
                    startButtonClicked = false;
                } else {
                    int row = event.mouseButton.y / CELL_SIZE;
                    int col = event.mouseButton.x / CELL_SIZE;
                    if (row < 3 && col < 3 && board[row][col] == '_') {
                        board[row][col] = selectedTeam;
                        selectedTeam = (selectedTeam == 'X') ? 'O' : 'X';
                        gameFinished = checkIfGameFinished(board, selectedTeam);
                        if (gameFinished) {
                            std::cout << "Congratulations! " << selectedTeam << " wins" << std::endl;
                        }
                    }
                }
            }
        }

        window.clear(sf::Color::White);
        
        if (!gameStarted) {
            window.draw(logoSprite);
            window.draw(startText);
        } else {
            drawBoard(window, board, font);
        }

        window.display();
    }

    return 0;
}