#include "../include/Segment.h"
#include <cmath>

Segment::Segment(sf::Vector2f start, float length, float angle) 
    : start(start), length(length), angle(angle) {
    // Calculate initial end point
    end.x = start.x + length * cos(angle * 3.14159f / 180.f);
    end.y = start.y + length * sin(angle * 3.14159f / 180.f);
}

void Segment::setAngle(float newAngle) {
    angle = newAngle;
    // Update end point when angle changes
    end.x = start.x + length * cos(angle * 3.14159f / 180.f);
    end.y = start.y + length * sin(angle * 3.14159f / 180.f);
}

void Segment::setStart(sf::Vector2f newStart) {
    start = newStart;
    // Update end point when start changes
    end.x = start.x + length * cos(angle * 3.14159f / 180.f);
    end.y = start.y + length * sin(angle * 3.14159f / 180.f);
}

sf::Vector2f Segment::getStart() const { return start; }
sf::Vector2f Segment::getEnd() const { return end; }
float Segment::getLength() const { return length; }
float Segment::getAngle() const { return angle; }

void Segment::draw(sf::RenderWindow& window) const {
    sf::Vertex line[] = {
        sf::Vertex(start, sf::Color::Black),
        sf::Vertex(end, sf::Color::Black)
    };
    window.draw(line, 2, sf::Lines);
}