#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <sstream>

#include "Bar.h"

// Just the initial configuration of some shapes
void setCircle(sf::CircleShape& circle, sf::RenderWindow& window);
void setBars(Bar& barOne, Bar& barTwo, Bar& barThree);
void setText(sf::Text& text, sf::Font& font);

// Updating the text on the screen
void updateText(sf::Text& text, int red, int green, int blue);

#endif // !FUNCTIONS_H

