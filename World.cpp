#include "World.hpp"
#include <fstream>
#include "Point.hpp"
#include "Velocity.hpp"

World::World(const std::string& worldFilePath) {
    std::ifstream stream(worldFilePath);
    if (!stream.is_open()) {
        throw std::runtime_error("Failed to open world file");
    }

    double x, y, vx, vy;
    int red, green, blue;
    double radius;
    bool isCollidable;

    while (stream.good()) {
        stream >> x >> y >> vx >> vy;
        stream >> red >> green >> blue;
        stream >> radius;
        stream >> std::boolalpha >> isCollidable;

        Point center(x, y);
        Velocity velocity(vx, vy);
        sf::Color color(red, green, blue);

        Ball ball(center, velocity, radius, radius * radius, color);
        balls_.push_back(ball);
    }
}

const std::vector<Ball>& World::getBalls() const {
    return balls_;
}
