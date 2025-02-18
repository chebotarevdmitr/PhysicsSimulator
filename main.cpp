#include <SFML/Graphics.hpp>
#include <iostream>
#include "World.hpp"
#include "Painter.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <world file>" << std::endl;
        return 1;
    }

    std::string worldFilePath = argv[1];
    World world(worldFilePath);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Physics Simulator");
    Painter painter(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (const auto& ball : world.getBalls()) {
            ball.draw(painter);
        }
        window.display();
    }

    return 0;
}