// Ball.cpp
#include "Ball.hpp"
#include "Velocity.hpp"

Ball::Ball(const Point& center, const Velocity& velocity, double radius, double mass, const sf::Color& color)
    : center_(center), velocity_(velocity), radius_(radius), mass_(mass), color_(color) {}

void Ball::setVelocity(const Velocity& velocity) {
    velocity_ = velocity;
}

Velocity Ball::getVelocity() const {
    return velocity_;
}

void Ball::setCenter(const Point& center) {
    center_ = center;
}

Point Ball::getCenter() const {
    return center_;
}

double Ball::getRadius() const {
    return radius_;
}

double Ball::getMass() const {
    return mass_;
}

void Ball::draw(Painter& painter) const {
    painter.drawCircle(center_, radius_, color_);
}