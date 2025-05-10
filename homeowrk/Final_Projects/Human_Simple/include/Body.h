// include/Body.h
#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Segment.h"

class Body {
protected:
    std::vector<Segment> segments;
    sf::Vector2f position;
    
public:
    Body(sf::Vector2f position);
    
    virtual void update();
    void draw(sf::RenderWindow& window) const;
    
    const std::vector<Segment>& getSegments() const;
    sf::Vector2f getPosition() const;
};