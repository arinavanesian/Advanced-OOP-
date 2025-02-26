#include <iostream>
using namespace std;

// Abstract class (Base class)
class Animal {
public:
    Animal(){cout<< "I am Animal"<<endl;}
    virtual void description() const = 0; // Pure virtual function (const)
    
    virtual ~Animal() {cout<<"Animal died!"<<endl;}= default; // Virtual destructor
};

// Concrete class (Derived class)
class Dog : public Animal {
public:
    Dog(){cout<< "Now I am a Dog" << endl;}
    void description() const override { // Must also be 'const'
        cout << "I am a Dog. I love to bark!" << endl;
    }
};

int main() {
    const Animal* myPet = new Dog(); // Base class pointer to derived class object

    myPet->description(); // Calls the Dog's implementation

    delete myPet; // Free memory
    return 0;
}

