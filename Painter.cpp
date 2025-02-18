#include "Painter.hpp"
#include "Point.hpp"

Painter::Painter(sf::RenderWindow& window) : window_(window) {}

void Painter::drawCircle(const Point& center, double radius, const sf::Color& color) {
    sf::CircleShape circle(radius);
    circle.setPosition(center.x - radius, center.y - radius);
    circle.setFillColor(color);
    window_.draw(circle);
}