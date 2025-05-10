#ifndef ANTHROPOMORPHIC_BODY_H
#define ANTHROPOMORPHIC_BODY_H

#include <vector>
#include "Point.h"
#include "Segment.h"
#include <cmath>

struct Circle
{
    Point center;
    double radius;
    Circle(Point c, double r) : center(c), radius(r) {
        radius = r;
        center = c;
    }
    Point operator*(double scalar) const
    {
        return Point(center.x * scalar, center.y * scalar);
    }
};

struct BodyState
{
    Point basePosition;
    std::vector<double> segmentAngles;
};

class AnthropomorphicBody
{
private:
    std::vector<Segment> segments;
    double groundLevel;
    Point currentPosition;

    void initializeBody()
    {
        segments = {
            // Torso (vertical)
            Segment(Point(0, 0), 1.2, -15, 15),  // Longer torso
            
            // Left arm (connected to torso top)
            Segment(Point(0, 1.2), 0.8, -135, 45),  // More natural arm range
            
            // Right arm
            Segment(Point(0, 1.2), 0.8, -45, 135),
            
            // Left leg (connected to torso bottom)
            Segment(Point(0, 0), 1.0, -45, 45),  // Longer legs
            
            // Right leg
            Segment(Point(0, 0), 1.0, -45, 45)
        };
    }

    // Update segment connections after movement
    void updateConnections()
    {
        // Position torso from the base position
        segments[0].setStart(currentPosition);
        
        // Arms connect to torso top
        segments[1].setStart(segments[0].getEnd());
        segments[2].setStart(segments[0].getEnd());
        
        // Legs connect to torso base
        segments[3].setStart(segments[0].getStart());
        segments[4].setStart(segments[0].getStart());
    }

public:
    AnthropomorphicBody(Point startPos, double groundY)
        : groundLevel(groundY), currentPosition(startPos)
    {
        initializeBody();
    }

    // Check stability (at least 2 contact points)
    bool isStable() const
    {
        int groundContacts = 0;
        for (const auto &seg : segments)
        {
            if (seg.getStart().y <= groundLevel)
                groundContacts++;
            if (seg.getEnd().y <= groundLevel)
                groundContacts++;
            if (groundContacts >= 2)
                return true;
        }
        return false;
    }

    // Check if body can grab target
    bool canGrab(const Circle &target) const
    {
        int contacts = 0;
        // Check arm endpoints
        for (int i : {1, 2})
        {
            double dx = segments[i].getEnd().x - target.center.x;
            double dy = segments[i].getEnd().y - target.center.y;
            if (dx * dx + dy * dy <= target.radius * target.radius)
            {
                contacts++;
            }
        }
        return contacts >= 1; // At least one arm touches
    }

    // Generate motion sequence
    std::vector<BodyState> generateCatchingMotion(const Circle &target)
    {
        std::vector<BodyState> plan;
        BodyState current = getCurrentState();
        
        // Simple approach: Move base toward target while maintaining upright posture
        double distToTarget = std::sqrt(std::pow(current.basePosition.x - target.center.x, 2) +
                              std::pow(current.basePosition.y - target.center.y, 2));
        
        double step = 0.2; // Step size for movement
        int numSteps = static_cast<int>(distToTarget / step) + 5; // Add extra steps for arm extension
        
        for (int i = 0; i < numSteps; i++) {
            // Calculate direction to target
            double t = static_cast<double>(i) / numSteps;
            
            // Update position - move toward target
            if (i < numSteps - 5) { // Move toward target except for last 5 steps
                Vector2D dir(target.center - current.basePosition);
                dir.normalize();
                current.basePosition += dir * step;
            }
            
            // Always keep torso upright
            current.segmentAngles[0] = 90.0; // Torso straight up
            
            // Walking motion for legs
            double legPhase = i * 0.5;
            current.segmentAngles[3] = -30.0 + 15.0 * sin(legPhase); // Left leg
            current.segmentAngles[4] = 30.0 + 15.0 * sin(legPhase + M_PI); // Right leg (opposite phase)
            
            // When close to target, reach with arms
            if (i >= numSteps - 5) {
                // Left arm gradually reaches down
                current.segmentAngles[1] = -135.0 + (i - (numSteps - 5)) * 20.0;
                
                // Right arm gradually reaches for target
                double targetAngle = atan2(target.center.y - segments[0].getEnd().y, 
                                          target.center.x - segments[0].getEnd().x) * 180.0 / M_PI;
                current.segmentAngles[2] = 135.0 + (targetAngle - 135.0) * (i - (numSteps - 5)) / 5.0;
            } else {
                // Normal arm position during walking
                double armPhase = i * 0.3;
                current.segmentAngles[1] = -135.0 + 10.0 * sin(armPhase); // Left arm
                current.segmentAngles[2] = 135.0 + 10.0 * sin(armPhase + M_PI); // Right arm (opposite phase)
            }
            
            plan.push_back(current);
        }

        return plan;
    }

    // Execute a movement step
    void moveStep(const BodyState &state)
    {
        currentPosition = state.basePosition;

        // Make sure we have the right number of angles
        if (state.segmentAngles.size() == segments.size()) {
            // Update each segment's angle
            for (size_t i = 0; i < segments.size(); ++i) {
                segments[i].rotate(state.segmentAngles[i]);
            }
        }

        updateConnections();
    }

    // Getters
    const std::vector<Segment> &getSegments() const { return segments; }
    double getGroundLevel() const { return groundLevel; }

    BodyState getCurrentState() const
    {
        BodyState state;
        state.basePosition = currentPosition;
        for (const auto &seg : segments) {
            Vector2D vec = seg.getEnd() - seg.getStart();
            state.segmentAngles.push_back(atan2(vec.y, vec.x) * 180.0 / M_PI);
        }
        return state;
    }
};

#endif