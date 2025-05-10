#include "Segment.h"
#include "Human.cpp"
#include <memory>
class HumanBuilder {
    public:
        static std::unique_ptr<Human> buildSimpleHuman(Point root) {
            auto human = std::make_unique<Human>();
    
            Segment leftLeg(root, 1.0, M_PI / 2);
            Segment rightLeg(Point(root.x + 0.3, root.y), 1.0, M_PI / 2);
            Segment torso(Point(root.x + 0.15, root.y + 1.0), 1.0, M_PI / 2);
            Segment head(Point(root.x + 0.15, root.y + 2.0), 0.3, M_PI / 2);
    
            human->addPart(BodyPart(leftLeg, "left_leg"));
            human->addPart(BodyPart(rightLeg, "right_leg"));
            human->addPart(BodyPart(torso, "torso"));
            human->addPart(BodyPart(head, "head"));
    
            return human;
        }
    };