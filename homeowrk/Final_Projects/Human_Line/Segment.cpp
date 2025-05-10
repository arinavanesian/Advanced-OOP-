#include "Segment.h"

Segment::Segment(Point start, double length, double angle)
    : start(start), length(length), angle(angle) {}

Point Segment::getEnd() const {
    return Point(start.x + length * cos(angle), start.y + length * sin(angle));
}

void Segment::rotate(double delta) {
    angle += delta;
}
