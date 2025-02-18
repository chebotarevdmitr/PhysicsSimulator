#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "Velocity.hpp"
#include "Point.hpp"
#include "Painter.hpp"

class Ball {
public:
    // Конструктор
    Ball(const Point& center, const Velocity& velocity, double radius, double mass, const sf::Color& color);

    // Сеттеры и геттеры
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;

    void setCenter(const Point& center);
    Point getCenter() const;

    double getRadius() const;
    double getMass() const;

    // Метод для отрисовки шара
    void draw(Painter& painter) const;

private:
    Point center_;       // Координаты центра шара
    Velocity velocity_;  // Скорость шара
    double radius_;      // Радиус шара
    double mass_;        // Масса шара
    sf::Color color_;    // Цвет шара
};

#endif // BALL_HPP