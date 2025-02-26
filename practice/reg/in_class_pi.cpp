#include <iostream>
#include <sstream>
#include <cmath> // For M_PI constant in C++17
using namespace std;

int main()
{
    printf("Using std::cout\n");
    std::cout << "Default Pi =\t\t\t3.1415" << std::endl;

    stringstream ss;
    ss << "Default Pi =\t\t\t" << M_PI; // Use M_PI for π (from <cmath>)
    cout << ss.str() << endl;

    return 0;
}
