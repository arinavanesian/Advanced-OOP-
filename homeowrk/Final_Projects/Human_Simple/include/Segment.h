#pragma once
#include <SFML/Graphics.hpp>

class Segment {
private:
    sf::Vector2f start;
    sf::Vector2f end;
    float length;
    float angle; 
    
public:
    Segment(sf::Vector2f start, float length, float angle = 0.f);
    
    void setAngle(float newAngle);
    void setStart(sf::Vector2f newStart);
    
    sf::Vector2f getStart() const;
    sf::Vector2f getEnd() const;
    float getLength() const;
    float getAngle() const;
    
    void draw(sf::RenderWindow& window) const;
};