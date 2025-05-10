#include <cmath>
#include <iostream>
#include "Application.cpp"
int main() {
    int steps;
    std::cout << "Enter number of steps: ";
    std::cin >> steps;
    runWalkerApp(steps);
    return 0;
}