#include "../include/Point.h"
#include <cmath>


// Point::Point(double x = 0, double y = 0) : x(x), y(y){}
// Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

Vector2D::Vector2D(const Point& p) : x(p.x), y(p.y) {}

void Vector2D::normalize() {
    double length = std::sqrt(x*x + y*y);
    if (length > 0) {
        x /= length;
        y /= length;
    }
}

Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}


Point Point::operator+(const Vector2D& vec) const {
    return Point(x + vec.x, y + vec.y);
}
Point& Point::operator+=(const Vector2D& vec) {
    x += vec.x;
    y += vec.y;
    return *this;  // Return reference to self
}

Point Point::operator-(const Vector2D& vec) const {
    return Point(x - vec.x, y - vec.y);
}

Vector2D Point::operator-(const Point& other) const {
    return Vector2D(x - other.x, y - other.y);
}