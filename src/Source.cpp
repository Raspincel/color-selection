#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream> // for std::cerr

#include "Bar.h"
#include "functions.h"


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window{ sf::VideoMode(800, 600), "Colors", sf::Style::Titlebar | sf::Style::Close };

    Bar redBar(window, 1);
    Bar greenBar(window, 2);
    Bar blueBar(window, 3);
    setBars(redBar, greenBar, blueBar);



    sf::CircleShape circle;
    setCircle(circle, window);

    sf::Font font;
    if (!font.loadFromFile("Fonts/Freshman.ttf"))
        std::cerr << "ERROR::GAME::INITFONTS::Failed to load font!" << '\n';

    sf::Text text;
    setText(text, font);

    int red{};
    int green{};
    int blue{};

    sf::Vector2i mousePos;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            mousePos = sf::Mouse::getPosition(window);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // Grab colors
                if (redBar.isInside(mousePos))
                    red = redBar.color(mousePos);

                else if (greenBar.isInside(mousePos))
                    green = greenBar.color(mousePos);

                else if (blueBar.isInside(mousePos))
                    blue = blueBar.color(mousePos);
            }

            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        window.clear(sf::Color(50, 50, 50, 255));

        // Update 
        updateText(text, red, green, blue);
        circle.setFillColor(sf::Color(red, green, blue, 255));


        // Render
        for (int i{ 0 }; i < 256; ++i)
        {
            window.draw(redBar[i]);
            window.draw(greenBar[i]);
            window.draw(blueBar[i]);
        }

        window.draw(circle);
        window.draw(text);
        window.display();
        
    }

    return 0;
}