#include "banner.h"

void adjustStringRowsToCurrentWindowSize(sf::RenderWindow& window, std::string &text, int fontSize){
  //Read string line by line and compare with current window size
  long unsigned int counter = 0;
  for(long unsigned int i = 0; i<text.length(); i++){
    if(text.at(i) != '\n'){
      counter++;
    } else if (text.at(i) == '\n'){
      counter = 0; 
    } 
    if(counter >= (window.getSize().x/(fontSize/2))){
      counter = 0;
      text = text.substr(0, i) + "\n      " + text.substr(i);
    } 
  }
}

void displayRules(sf::RenderWindow& window, sf::Font& font) {
    bool firstClickOccured = false;
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
    )";

    sf::Event event;
    while (window.isOpen()) {
        adjustStringRowsToCurrentWindowSize(window,rules,15);
        sf::Text rulesText(rules, font, 15);
        rulesText.setFillColor(sf::Color::Black);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Close the window properly
            } else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed) {
                if (!firstClickOccured) {
                    firstClickOccured = true;
                    break;
                }
            }
            if(firstClickOccured){
              break;
            }
        }
        if(firstClickOccured){
              break;
        }
        // Clear, draw, and display
        window.clear(sf::Color::White);
        window.draw(rulesText);
        window.display();
    }

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