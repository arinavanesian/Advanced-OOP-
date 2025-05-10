#include <cmath>
#include <iostream>
#include "Segment.h"
struct BodyPart {
    Segment segment;
    std::string name; // e.g. "left_leg"

    BodyPart(Segment seg, std::string name = "") : segment(seg), name(name) {}
};