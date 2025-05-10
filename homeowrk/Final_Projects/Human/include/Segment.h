#ifndef SEGMENT_H
#define SEGMENT_H

#include "Point.h" 

class Segment {
private:
    Point start;
    Point end;
    double length;
    double minAngle;  
    double maxAngle; 

public:
    Segment(Point start, double length, double minAngle, double maxAngle);
        void rotate(double angleDegrees);
    void translate(double dx, double dy);
    
    Point getStart() const;
    Point getEnd() const;
    
    void setStart(const Point& newStart);
};

#endif