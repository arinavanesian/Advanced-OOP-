#include "point.h"
import <iostream>;
import <format>;
using namespace std;

int main()
{
    point a, b(1, 1);

    cout << format("Dist between a and b: {}", a.dist(b)) << endl;
    cout << format("Dir  between a and b: {}", a.dir(b))  << endl;

    double* ptr;
    ptr = (double*)&a;
    ptr[0] = 2;
    ptr[1] = 1;

    cout << format("Dist between a and b: {}", a.dist(b)) << endl;
    cout << format("Dir  between a and b: {}", a.dir(b)) << endl;
}