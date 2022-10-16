#pragma once
#ifndef BAR_H
#define BAR_H

#include <SFML/Graphics.hpp>

class Bar
{
private:
	sf::RectangleShape m_bar[256];

	// To measure where the color bars are in the screen
	int m_xLimits[2];
	int m_yLimits[2];

	// Private functions
	void createBar(sf::RenderWindow&, int number);


public:
	// Constructor
	Bar(sf::RenderWindow& window, int numberOfBar) 
	{ 
		createBar(window, numberOfBar); 
	} 

	~Bar()
	{
		// delete m_bar;
	}
	

	// Change colors of the bars 
	void setColor(sf::Color);
	void setColorRed() { setColor(sf::Color::Red); }
	void setColorGreen() { setColor(sf::Color::Green); }
	void setColorBlue() { setColor(sf::Color::Blue); }

	// Check if the mouse click is over some color, and what color
	bool isInside(sf::Vector2i& mousePosition);
	int color(sf::Vector2i& mousePosition);

	// Overloaded operators
	sf::RectangleShape operator[](int index)
	{
		return m_bar[index];
	}

};

#endif // !BAR_H
