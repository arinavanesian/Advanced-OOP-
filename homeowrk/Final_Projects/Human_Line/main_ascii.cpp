#include "Application.cpp"
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

void clearScreen() {
    std::system("clear"); // Use "cls" on Windows
}

void drawAscii(const Human& human) {
    const int width = 60;
    const int height = 20;
    std::vector<std::string> canvas(height, std::string(width, ' '));

    for (const auto& part : human.parts) {
        Point start = part.segment.start;
        Point end = part.segment.getEnd();

        int x1 = static_cast<int>(start.x + width / 2);
        int y1 = height - static_cast<int>(start.y) - 1;
        int x2 = static_cast<int>(end.x + width / 2);
        int y2 = height - static_cast<int>(end.y) - 1;

        if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < height)
            canvas[y1][x1] = '+';
        if (x2 >= 0 && x2 < width && y2 >= 0 && y2 < height)
            canvas[y2][x2] = '+';
    }

    for (const auto& row : canvas)
        std::cout << row << '\n';
}

int main() {
    int steps;
    std::cout << "Enter number of walking steps: ";
    std::cin >> steps;

    auto human = HumanBuilder::buildSimpleHuman(Point(0, 0));

    for (int i = 0; i < steps; ++i) {
        clearScreen();
        drawAscii(*human);
        human->moveStep(1.0);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
