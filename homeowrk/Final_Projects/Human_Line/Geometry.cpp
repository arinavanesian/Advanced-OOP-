#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <utility>


struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Line {
public:
    Point p1, p2;
    Line(Point a, Point b) : p1(a), p2(b) {}
};

class Segment {
public:
    Point start;
    double length;
    double angle; // radians

    Segment(Point start, double length, double angle)
        : start(start), length(length), angle(angle) {}

    Point getEnd() const {
        return Point(start.x + length * cos(angle), start.y + length * sin(angle));
    }

    void rotate(double delta) {
        angle += delta;
    }
};