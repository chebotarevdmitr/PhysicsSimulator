#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
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
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        // Обработка событий
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Обновление позиций шаров
        for (auto& ball : world.getBallsMutable()) {
            Point center = ball.getCenter();
            Velocity velocity = ball.getVelocity();
            double radius = ball.getRadius();

            // Обновление позиции
            center.x += velocity.vx * deltaTime.asSeconds();
            center.y += velocity.vy * deltaTime.asSeconds();

            // Обработка столкновений с границами
            if (center.x < radius) {
                center.x = radius;
                velocity.vx = -velocity.vx;
            } else if (center.x > 800 - radius) {
                center.x = 800 - radius;
                velocity.vx = -velocity.vx;
            }

            if (center.y < radius) {
                center.y = radius;
                velocity.vy = -velocity.vy;
            } else if (center.y > 600 - radius) {
                center.y = 600 - radius;
                velocity.vy = -velocity.vy;
            }

            ball.setCenter(center);
            ball.setVelocity(velocity);
        }

        // Отрисовка
        window.clear(sf::Color::White); // Белый фон
        for (const auto& ball : world.getBalls()) {
            ball.draw(painter);
        }
        window.display();
    }

    return 0;
}