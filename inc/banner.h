#ifndef BANNER_H
#define BANNER_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

void displayTicTacToe();
void displayRules(sf::RenderWindow& window, sf::Font& font);

void adjustStringRowsToCurrentWindowSize(long unsigned int windowSize, std::string &text, int fontSize);

#endif // BANNER_H