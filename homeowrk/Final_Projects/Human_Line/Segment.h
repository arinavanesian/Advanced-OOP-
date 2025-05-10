#pragma once
#include "Point.h"
#include <cmath>

class Segment {
public:
    Point start;
    double length;
    double angle;

    Segment(Point start, double length, double angle);
    Point getEnd() const;
    void rotate(double delta);
};
