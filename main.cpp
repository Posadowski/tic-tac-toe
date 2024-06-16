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

    // Create "Start Game" text
    sf::Text rulesText("Rules", font, 50);
    rulesText.setFillColor(sf::Color::Black);
    rulesText.setPosition((WINDOW_WIDTH - rulesText.getLocalBounds().width) / 2, 500);

    bool gameStarted = false;
    bool startButtonClicked = false; // State to handle the start button click
    bool rulesButtonClicked = false; // State to handle the start button click

    // Initial game board
    std::vector<std::vector<char>> board(3, std::vector<char>(3, UNCHECKED_BOX));
    char selectedTeam = 'X';
    possible_match_results gameResult = MATCH_RESULT_UNKNOWN;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && !gameStarted) {
                // Check if the "Start Game" text is clicked
                sf::FloatRect startBounds  = startText.getGlobalBounds();
                if (startBounds .contains(event.mouseButton.x, event.mouseButton.y)) {
                    gameStarted = true;
                    startButtonClicked = true; // Set the flag to ignore the first mouse press after starting the game
                }

                sf::FloatRect rulesBounds = rulesText.getGlobalBounds();
                if (rulesBounds.contains(event.mouseButton.x, event.mouseButton.y)) {
                    rulesButtonClicked = true; // Set the flag to ignore the first mouse press after starting the game
                }
            }

            if (event.type == sf::Event::Resized) {
                // Update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));

                // Rescale logo
                logoSprite.setScale(event.size.width / float(logoTexture.getSize().x), (event.size.height / 2) / float(logoTexture.getSize().y));
                logoSprite.setPosition(0, 0);

                // Reposition "Start Game" text
                startText.setPosition((event.size.width - startText.getLocalBounds().width) / 2, event.size.height - 200);
                rulesText.setPosition((event.size.width - startText.getLocalBounds().width) / 2, event.size.height - 100);
            }

            if (event.type == sf::Event::MouseButtonPressed && gameStarted && gameResult == MATCH_RESULT_UNKNOWN) {
                if (startButtonClicked) {
                    // Ignore the first mouse press after clicking "Start Game"
                    startButtonClicked = false;
                } else {
                    int row = event.mouseButton.y / CELL_SIZE;
                    int col = event.mouseButton.x / CELL_SIZE;
                    if (row < 3 && col < 3 && board[row][col] == '_') {
                        board[row][col] = selectedTeam;
                        selectedTeam = (selectedTeam == 'X') ? 'O' : 'X';
                        gameResult = checkIfGameFinished(board, selectedTeam);
                    }
                }
            }
        }

        window.clear(sf::Color::White);
        
        if (!gameStarted) {
            if(!rulesButtonClicked){
                window.draw(logoSprite);
                window.draw(startText);
                window.draw(rulesText);
            } else {
                displayRules(window,font);
                rulesButtonClicked = false;
            }
        } else {
            if(gameResult == MATCH_RESULT_UNKNOWN){
                drawBoard(window, board, font);
            } else {
                drawResult(window,font,selectedTeam,gameResult);
                // reset all
                std::cout << "here" << std::endl;
                gameStarted = false;
                gameResult = MATCH_RESULT_UNKNOWN;
                board = {
                    { UNCHECKED_BOX, UNCHECKED_BOX, UNCHECKED_BOX },
                    { UNCHECKED_BOX, UNCHECKED_BOX, UNCHECKED_BOX },
                    { UNCHECKED_BOX, UNCHECKED_BOX, UNCHECKED_BOX }
                };
            }
        }

        window.display();
    }

    return 0;
}