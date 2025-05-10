// == Simple Walker with Builder Factory Pattern + Limb Animation ==
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include "HumanBuilder.cpp"
void runWalkerApp(int steps) {
    auto human = HumanBuilder::buildSimpleHuman(Point(0, 0));
    human->display();

    for (int i = 1; i <= steps; ++i) {
        human->moveStep(0.5); // Move 0.5 units forward
        std::cout << "After step " << i << ":\n";
        human->display();
    }
}

