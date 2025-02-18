#ifndef POINT_HPP
#define POINT_HPP

struct Point {
    double x;  // Координата X
    double y;  // Координата Y

    // Конструктор с параметрами
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

#endif // POINT_HPP