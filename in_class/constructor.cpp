#include <iostream>
using namespace std;

class Shape {
public:
    virtual ~Shape() {  // Virtual destructor
        cout << "Shape destructor called" << endl;
    }
};

class Circle : public Shape {
public:
    ~Circle() {
        cout << "Circle destructor called" << endl;
    }
};



int main() {
    Shape* shape = new Circle();
    delete shape; // Calls ~Circle() first,
                  //then ~Shape()
    return 0;
}
