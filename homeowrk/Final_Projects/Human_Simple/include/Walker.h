#pragma once
#include "Body.h"

class Walker : public Body {
private:
    sf::Vector2f target;
    float targetRadius;
    bool objectCaught;
    
public:
    Walker(sf::Vector2f position, sf::Vector2f target, float targetRadius);
    void update() override;
    bool hasCaughtObject() const;
    void setTarget(sf::Vector2f newTarget);
    
    float getTargetRadius() const { return targetRadius; }
    sf::Vector2f getTargetPosition() const { return target; }
};