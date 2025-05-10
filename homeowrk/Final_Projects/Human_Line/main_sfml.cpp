#include <SFML/Graphics.hpp>
#include "Application.cpp"
#include <thread>
#include <chrono>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Walker Animation");

    auto human = HumanBuilder::buildSimpleHuman(Point(5, 0));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        static int frame = 0;
        if (frame % 30 == 0) {
            human->moveStep(0.3);
        }
        ++frame;

        window.clear(sf::Color::White);

        for (const auto& part : human->parts) {
            Point start = part.segment.start;
            Point end = part.segment.getEnd();

            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(start.x * 50, 600 - start.y * 50), sf::Color::Black),
                sf::Vertex(sf::Vector2f(end.x * 50, 600 - end.y * 50), sf::Color::Black)
            };

            window.draw(line, 2, sf::Lines);
        }

        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60 FPS
    }

    return 0;
}
