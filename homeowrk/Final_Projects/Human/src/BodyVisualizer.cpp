#include "../include/AnthropomorphicBody.h"
#include "../include/Point.h"
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <iostream> 

class BodyVisualizer {
private:
    sf::RenderWindow window;
    const float scale;
    const float offsetX, offsetY;

    sf::Vector2f toScreenCoords(const Point& p) const {
        return {
            offsetX + static_cast<float>(p.x) * scale,
            offsetY - static_cast<float>(p.y) * scale
        };
    }

public:
    BodyVisualizer(int width = 800, int height = 600, float scale = 50.0f) :
        window(sf::VideoMode(width, height), "OOCatcher Visualization"),
        scale(scale),
        offsetX(width/2.0f),
        offsetY(height*0.75f)
    {
        if (!window.isOpen()) {
            throw std::runtime_error("Failed to create SFML window");
        }
    }

    void drawBody(const AnthropomorphicBody& body) {
        
        // drawBody code starts with clearing the window and drawing the ground line.
        // It then iterates through the segments of the body, drawing each segment as a line
        // and each joint as a circle. Finally, it draws the end effector if segments exist.
        
        window.clear(sf::Color::White);
        const float groundY = offsetY - static_cast<float>(body.getGroundLevel()) * scale;
        sf::Vertex ground[] = {
            sf::Vertex(sf::Vector2f(0, groundY), sf::Color::Black),
            sf::Vertex(sf::Vector2f(window.getSize().x, groundY), sf::Color::Black)};
        window.draw(ground, 2, sf::Lines);

        const auto& segments = body.getSegments();
        for (const auto& segment : segments) {
            sf::Vertex line[] = {
                sf::Vertex(toScreenCoords(segment.getStart()), sf::Color::Blue),
                sf::Vertex(toScreenCoords(segment.getEnd()), sf::Color::Blue)
            };
            window.draw(line, 2, sf::Lines);
            sf::CircleShape joint(5.0f);
            joint.setFillColor(sf::Color::Red);
            joint.setOrigin(5.0f, 5.0f);
            joint.setPosition(toScreenCoords(segment.getStart()));
            window.draw(joint);
        }

        if (!segments.empty()) {
            sf::CircleShape endEffector(8.0f);
            endEffector.setFillColor(sf::Color::Green);
            endEffector.setOrigin(8.0f, 8.0f);
            endEffector.setPosition(toScreenCoords(segments.back().getEnd()));
            window.draw(endEffector);
        }
        window.display(); 
    }

    void drawTarget(const Circle& target) {
        const float radius = static_cast<float>(target.radius) * scale;
        sf::CircleShape targetCircle(radius);
        targetCircle.setFillColor(sf::Color(100, 255, 100, 200)); 
        targetCircle.setOutlineThickness(2.0f);
        targetCircle.setOutlineColor(sf::Color::Yellow);  
        targetCircle.setOrigin(radius, radius);
        targetCircle.setPosition(toScreenCoords(target.center));
        window.draw(targetCircle);
    }

    bool isOpen() const { return window.isOpen(); }

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
};

int main() {
    try {
        BodyVisualizer visualizer;
        
        AnthropomorphicBody body(Point(0, 0), 0.0);
        
        BodyState initialState;
        initialState.basePosition = Point(0, 0);
        // Initial angles for torso, left arm, right arm, left leg, right leg
        // Torso at 90 degrees (pointing straight up)
        // Left arm at -135 degrees (pointing left and down)
        // Right arm at 135 degrees (pointing right and down)
        // Left leg at -30 degrees (pointing left and down)
        // Right leg at 30 degrees (pointing right and down)
        initialState.segmentAngles = {90.0, -135.0, 135.0, -30.0, 30.0};
        body.moveStep(initialState);
        
        Circle target{Point(5.0, 0.0), 0.5}; 
        
        auto motionPlan = body.generateCatchingMotion(target);
        
        for (const auto& state : motionPlan) {
            if (!visualizer.isOpen()) break;

            body.moveStep(state);
            
            visualizer.handleEvents();
            visualizer.drawBody(body);
            visualizer.drawTarget(target);
            sf::sleep(sf::milliseconds(100));
        }

        while (visualizer.isOpen()) {
            visualizer.handleEvents();
            visualizer.drawBody(body);
            visualizer.drawTarget(target);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}