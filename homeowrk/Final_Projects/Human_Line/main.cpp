#include "Application.cpp"
#include <thread>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

void clearScreen() {
    std::system("clear");
    // std::cout << "\033[2J\033[1;1H";  // ANSI escape codes
}

void drawHuman(const Human& human, int step_count) {
    const int width = 60;
    const int height = 30;
    std::vector<std::string> canvas(height, std::string(width, ' '));

    canvas[height-1] = std::string(width, '=');

    const std::unordered_map<std::string, std::pair<char, char>> part_chars = {
        {"head", {' ', 'O'}},
        {"torso", {'|', '|'}},
        {"upper_arm", {'/', '/'}}, {"lower_arm", {'-', '-'}},
        {"upper_leg", {'\\', '\\'}}, {"lower_leg", {'|', '|'}}
    };

    for (const auto& part : human.parts) {
        Point start = part.segment.start;
        Point end = part.segment.getEnd();

        int x1 = static_cast<int>(start.x * 4 + width/3);
        int y1 = height/2 - static_cast<int>(start.y * 3);
        int x2 = static_cast<int>(end.x * 4 + width/3);
        int y2 = height/2 - static_cast<int>(end.y * 3);

        char c = '|'; // default
        char joint = 'O';
        for (const auto& [key, chars] : part_chars) {
            if (part.name.find(key) != std::string::npos) {
                c = chars.first;
                joint = chars.second;
                break;
            }
        }
        int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
        int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
        int err = (dx > dy ? dx : -dy)/2;

        while (true) {
            if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < height) {
                if (canvas[y1][x1] == ' ') {
                    canvas[y1][x1] = c;
                }
            }

            if (x1 == x2 && y1 == y2) break;
            int e2 = err;
            if (e2 > -dx) { err -= dy; x1 += sx; }
            if (e2 < dy) { err += dx; y1 += sy; }
        }

        // Draw joints
        if (x1 >= 0 && x1 < width && y1 >= 0 && y1 < height) {
            canvas[y1][x1] = joint;
        }
    }

    std::string walk_indicator = (step_count % 2) ? " >> " : " << ";
    canvas[height-1][width/2] = walk_indicator[0];
    canvas[height-1][width/2+1] = walk_indicator[1];

    std::cout << "\n";
    for (const auto& row : canvas) {
        std::cout << "  " << row << "\n";
    }
    std::cout << "  Steps: " << step_count << "\n";
}

int main() {
    int steps;
    std::cout << "Enter number of walking steps: ";
    std::cin >> steps;

    auto human = HumanBuilder::buildSimpleHuman(Point(0, 0));

    for (int i = 0; i < steps; ++i) {
        clearScreen();
        drawHuman(*human, i+1);
        human->moveStep(1.0);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    clearScreen();
    drawHuman(*human, steps);
    std::cout << "\n  Walk completed! (" << steps << " steps)\n\n";

    return 0;
}