#include "World.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Point.hpp"
#include "Velocity.hpp"

World::World(const std::string& worldFilePath) {
    std::ifstream stream(worldFilePath);
    if (!stream.is_open()) {
        throw std::runtime_error("Failed to open world file");
    }

    std::string line;
    while (std::getline(stream, line)) {
        if (line.empty() || line[0] == '#') continue; // Пропуск пустых строк и комментариев

        std::istringstream iss(line);
        double x, y, vx, vy;
        int red, green, blue;
        double radius;
        bool isCollidable;

        if (!(iss >> x >> y >> vx >> vy 
                   >> red >> green >> blue 
                   >> radius 
                   >> std::boolalpha >> isCollidable)) {
            std::cerr << "Skipping invalid line: " << line << std::endl;
            continue;
        }

        Point center(x, y);
        Velocity velocity(vx, vy);
        sf::Color color(red, green, blue);

        balls_.emplace_back(center, velocity, radius, radius * radius, color);
    }
}

const std::vector<Ball>& World::getBalls() const {
    return balls_;
}

std::vector<Ball>& World::getBallsMutable() {
    return balls_;
}
