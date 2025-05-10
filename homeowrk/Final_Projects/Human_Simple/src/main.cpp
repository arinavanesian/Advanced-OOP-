// src/main.cpp
#include <SFML/Graphics.hpp>
#include "../include/Walker.h"
#include "../include/Body.h"
#include "../include/Segment.h"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "OOCatcher");

    Walker walker(sf::Vector2f(300, 400), sf::Vector2f(600, 400), 30);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::sleep(sf::milliseconds(30));
        walker.update();
        
        window.clear(sf::Color::White);
        walker.draw(window);
        
        sf::CircleShape target(walker.getTargetRadius());
        target.setPosition(walker.getTargetPosition());
        target.setFillColor(sf::Color::Red);
        window.draw(target);
        
        window.display();
    }
    
    return 0;
}