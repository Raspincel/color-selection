#include "Bar.h"

// Constructor
void Bar::createBar(sf::RenderWindow& window, int numberOfBar)
{
	// m_bar = new sf::RectangleShape[256];
	// freee();

	for (int i{ 0 }; i < 256; ++i)
		m_bar[i].setSize(sf::Vector2<float>(1, 50));
	

	float x{ static_cast<float>((window.getSize().x / 2)) - 128 };
	float y{ static_cast<float>(((window.getSize().y / 2))) + ((numberOfBar - 1) * 60)};

	for (int i{ 0 }; i < 256; ++i)
		m_bar[i].setPosition(x + i, y);


	// Useful to check coordinates of the colors later
	int intX = static_cast<int>(x);
	int intY = static_cast<int>(y);

	m_xLimits[0] = intX;
	m_xLimits[1] = intX + 255;
	m_yLimits[0] = intY;
	m_yLimits[1] = intY + 50;
}


// Private functions

void Bar::setColor(sf::Color color)
{
	if (color == sf::Color::Red)
		for (int i{ 0 }; i < 256; ++i)
			m_bar[i].setFillColor(sf::Color(i, 0, 0, 255));
	else if (color == sf::Color::Green)
		for (int i{ 0 }; i < 256; ++i)
			m_bar[i].setFillColor(sf::Color(0, i, 0, 255));
	else if (color == sf::Color::Blue)
		for (int i{ 0 }; i < 256; ++i)
			m_bar[i].setFillColor(sf::Color(0, 0, i, 255));
}


// Check if the mouse click is over some color, and what color

bool Bar::isInside(sf::Vector2i& mousePosition)
{
	
	//auto mousePos = window.mapPixelToCoords(mousePosition);
	// if (m_bar[i].getGlobalBounds().contains(mousePos)) return true
	// The above could be used in a loop, but I guess it would be a little inefficient?
	// I mean, the below already works, and all it uses is basic arithmetics, so let it be

	int x = mousePosition.x;
	int y = mousePosition.y;

	return x >= m_xLimits[0] && x <= m_xLimits[1] && y >= m_yLimits[0] && y <= m_yLimits[1];
}

int Bar::color(sf::Vector2i& mousePosition)
{
	return mousePosition.x - m_xLimits[0];
}
