#include "../include/Walker.h"
#include <cmath> 
#include <iostream>
Walker::Walker(sf::Vector2f position, sf::Vector2f target, float targetRadius)
    : Body(position), target(target), targetRadius(targetRadius), objectCaught(false) {}

void Walker::update() {
    std::cout << "Updating Walker..." << std::endl;  // Debug print
    if (objectCaught) return;
    // Simple walking animation - alternate leg movements
    static bool rightLegForward = true;
    float legAngle = rightLegForward ? 20.f : -20.f;
    
    // Update leg angles (segments 3 and 4)
    segments[3].setAngle(legAngle);
    segments[4].setAngle(-legAngle);
    
    // Move body forward slightly
    position.x += 1.f;
    segments[0].setStart(position);
    
    // Update connected segments
    for (size_t i = 1; i < segments.size(); ++i) {
        segments[i].setStart(segments[i-1].getEnd());
    }
    
    // Toggle leg movement
    static int counter = 0;
    if (++counter > 30) {
        rightLegForward = !rightLegForward;
        counter = 0;
    }
    
    // Check if object is caught (simplified collision)
    for (const auto& segment : segments) {
        sf::Vector2f end = segment.getEnd();
        float dx = end.x - target.x;
        float dy = end.y - target.y;
        float distance = sqrt(dx*dx + dy*dy);
        
        if (distance <= targetRadius) {
            objectCaught = true;
            break;
        }
    }
}

bool Walker::hasCaughtObject() const { return objectCaught; }

void Walker::setTarget(sf::Vector2f newTarget) { target = newTarget; }