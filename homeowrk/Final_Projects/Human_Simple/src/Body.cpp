#include "../include/Body.h"

Body::Body(sf::Vector2f position) : position(position) {
    // Create a simple 5-segment body (like in Fig. 1)
    segments.emplace_back(position, 100.f, 90.f);  // Head/body (was 50.f)
    segments.emplace_back(segments[0].getEnd(), 60.f, 45.f);  // Arm (was 30.f)
    segments.emplace_back(segments[0].getEnd(), 60.f, -45.f); // Arm (was 30.f)
    segments.emplace_back(segments[0].getEnd(), 80.f, 0.f);   // Leg (was 40.f)
    segments.emplace_back(segments[0].getEnd(), 80.f, 0.f);   // Leg (was 40.f)
}

void Body::update() {
    // Base body doesn't move by itself
}

void Body::draw(sf::RenderWindow& window) const {
    for (const auto& segment : segments) {
        segment.draw(window);
    }
}

const std::vector<Segment>& Body::getSegments() const { return segments; }
sf::Vector2f Body::getPosition() const { return position; 
}