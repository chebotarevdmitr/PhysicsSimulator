#ifndef PAINTER_HPP
#define PAINTER_HPP

#include <SFML/Graphics.hpp>
#include "Point.hpp"

class Painter {
public:
    Painter(sf::RenderWindow& window);

    void drawCircle(const Point& center, double radius, const sf::Color& color);

private:
    sf::RenderWindow& window_;  // Окно для отрисовки
};

#endif // PAINTER_HPP