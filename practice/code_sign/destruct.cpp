#include <iostream>
#include <string>
using namespace std;
class A {
public:
    A() { std::cout << "A "; }
    ~A() { std::cout << "~A "; }
};

class B : public A {
public:
    B() { std::cout << "B "; }
    ~B() { std::cout << "~B "; }
};

int main() {
    A* obj = new B();
    delete obj;
    return 0;
}

