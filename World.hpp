#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include <string>
#include "Ball.hpp"

class World {
public:
    World(const std::string& worldFilePath);
    const std::vector<Ball>& getBalls() const;
    std::vector<Ball>& getBallsMutable();

private:
    std::vector<Ball> balls_;
};

#endif // WORLD_HPP