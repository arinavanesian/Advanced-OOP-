#include "BodyPart.cpp"
#include "Segment.h"
#include <vector>
class Human {
    public:
        std::vector<BodyPart> parts;
        bool leftForward = true;
    
        void addPart(const BodyPart& part) {
            parts.push_back(part);
        }

    void moveStep(double dx) {
        for (auto& part : parts) {
            if (part.name == "left_leg") {
                part.segment.rotate(leftForward ? 0.1 : -0.1);
            }
            if (part.name == "right_leg") {
                part.segment.rotate(leftForward ? -0.1 : 0.1);
            }
        }
        leftForward = !leftForward;

        for (auto& part : parts) {
            part.segment.start.x += dx;
        }
    }

    void display() const {
        std::cout << "Human body structure:\n";
        for (const auto& part : parts) {
            Point end = part.segment.getEnd();
            std::cout << part.name << " from (" << part.segment.start.x << ", " << part.segment.start.y
                    << ") to (" << end.x << ", " << end.y << ")\n";
        }
        std::cout << "---------------------------\n";
    }
};