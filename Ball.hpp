#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "Velocity.hpp"
#include "Point.hpp"

class Painter;

class Ball {
public:
    Ball(const Point& center, const Velocity& velocity, double radius, double mass, const sf::Color& color);
    
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    
    void setCenter(const Point& center);
    Point getCenter() const;
    
    double getRadius() const;
    double getMass() const;
    
    void draw(Painter& painter) const;

private:
    Point center_;
    Velocity velocity_;
    double radius_;
    double mass_;
    sf::Color color_;
};

#endif // BALL_HPP