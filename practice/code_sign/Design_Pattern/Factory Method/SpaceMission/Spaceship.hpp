#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <iostream>
using namespace std;
// TODO: Define an interface  with a pure virtual function blastOff()
class Spaceship{
public:
    virtual ~Spaceship() = default;
    virtual void blastOff() = 0;
};
// TODO: Define  class that inherits from Spaceship and implements blastOff()
class NASASpaceship:public Spaceship{
public:
    void blastOff() override{
        cout<< "NASASpaceship blast Off..."<<endl;
    }    
};
// TODO: Define  class that inherits from Spaceship and implements blastOff()
class SpaceXSpaceship:public Spaceship{
public:
    void blastOff() override{
        cout<< "SpaceXSpaceship blast Off..."<<endl;
    }    
};
#endif // SPACESHIP_H
