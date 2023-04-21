#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Vector Graphics");
    
    // create a shape
    sf::CircleShape circle(100);
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(5);
    circle.setPosition(350, 250);
    
    // create a line
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(50, 50)),
        sf::Vertex(sf::Vector2f(750, 550))
    };
    line[0].color = sf::Color::Blue;
    line[1].color = sf::Color::Green;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(sf::Color::White);
        
        // draw the shape and line
        window.draw(circle);
        window.draw(line, 2, sf::Lines);
        
        window.display();
    }
    
    return 0;
}
