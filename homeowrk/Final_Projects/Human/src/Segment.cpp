#include "../include/Segment.h"
#include "../include/Point.h"
#include <cmath>
#include <algorithm>

Segment::Segment(Point start, double length, double minAngle, double maxAngle)
    : start(start), length(length), minAngle(minAngle), maxAngle(maxAngle)
{
    end = Point(start.x + length, start.y);
}

void Segment::rotate(double angleDegrees)
{
    double angleRad = angleDegrees * M_PI / 180.0;
    angleRad = std::clamp(angleRad, 
                         minAngle * M_PI / 180.0,
                         maxAngle * M_PI / 180.0);

    end.x = start.x + length * cos(angleRad);
    end.y = start.y + length * sin(angleRad);
}

void Segment::translate(double dx, double dy)
{
    start.x += dx;
    start.y += dy;
    end.x += dx;
    end.y += dy;
}

Point Segment::getStart() const { return start; }
Point Segment::getEnd() const { return end; }

void Segment::setStart(const Point& newStart)
{
    Vector2D direction = end - start;
    start = newStart;
    end = start + direction;
}