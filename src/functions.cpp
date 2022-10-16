#include "functions.h"

// Just the initial configuration of some shapes
void setCircle(sf::CircleShape& circle, sf::RenderWindow& window)
{
    float x{ static_cast<float>((window.getSize().x / 2)) - 75 };
    float y{ static_cast<float>(((window.getSize().y / 2))) - 200 };

    circle.setPosition(x, y);
    circle.setFillColor(sf::Color::Black);
    circle.setRadius(75);
}

void setBars(Bar& barOne, Bar& barTwo, Bar& barThree)
{
    barOne.setColorRed();
    barTwo.setColorGreen();
    barThree.setColorBlue();
}


void setText(sf::Text& text, sf::Font& font)
{
    text.setFont(font);
    text.setCharacterSize(21);
    text.setFillColor(sf::Color::White);
    text.setLineSpacing(1.5f);
}


// Updating the text on the screen
void updateText(sf::Text& text, int red, int green, int blue)
{
    std::stringstream ss;

    ss << "Red: " << red << '\n' <<
        "Green: " << green << '\n' <<
        "Blue: " << blue << '\n';

    text.setString(ss.str());
}