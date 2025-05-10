#ifndef POINT_H
#define POINT_H

#include <cmath>

struct Vector2D;

struct Point {
    double x, y;
    
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    Point operator+(const Vector2D& vec) const;
    Point operator-(const Vector2D& vec) const;
    Point& operator+=(const Vector2D& vec);
    Vector2D operator-(const Point& other) const;
    
    Point operator*(double scalar) const {
        return Point(x * scalar, y * scalar);
    }
};

struct Vector2D {
    double x, y;
    // Constructors
    Vector2D(double x, double y) : x(x), y(y) {}
    Vector2D(const Point& p);
    
    void normalize();
    Vector2D operator*(double scalar) const;
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
};

#endif