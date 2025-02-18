#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <string>
#include "Ball.hpp"

class World {
public:
    World(const std::string& worldFilePath);

    const std::vector<Ball>& getBalls() const;

private:
    std::vector<Ball> balls_;  // Вектор шаров
};

#endif // WORLD_HPP