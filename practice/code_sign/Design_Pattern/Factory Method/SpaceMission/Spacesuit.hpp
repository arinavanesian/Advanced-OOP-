#ifndef SPACESUIT_H
#define SPACESUIT_H

#include <iostream>
using namespace std;
// TODO: Define an interface SpaceSuit with a pure virtual function wear()
class SpaceSuit{
public:
    virtual ~SpaceSuit() = default;
    virtual void wear() = 0;
};
// TODO: Define  class that inherits from Spaceship and implements blastOff()
class NASASpaceSuit:public SpaceSuit{
public:
    void wear() override{
        cout<< "NASASpaceSuit wearing..."<<endl;
    }    
};
// TODO: Define  class that inherits from Spaceship and implements blastOff()
class SpaceXSpaceSuit:public SpaceSuit{
public:
    void wear() override{
        cout<< "SpaceXSpaceSuit wearing..."<<endl;
    }    
};
#endif // SPACESUIT_H
