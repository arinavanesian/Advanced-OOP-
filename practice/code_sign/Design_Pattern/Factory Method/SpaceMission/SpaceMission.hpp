#ifndef SPACEMISSION_H
#define SPACEMISSION_H

#include "Factory.hpp"
using namespace std;
// TODO: Define a SpaceMission class with a constructor accepting SpaceFactory*, methods prepare(), and destructor to cleanup
class SpaceMission{
public:
    SpaceMission(SpaceFactory* factory): factory(factory){
        spacesuit = factory->createSpaceSuit();
        spaceship=factory->createSpaceship();
    }
    void prepare(){
        spacesuit->wear();
        spaceship->blastOff();
    }
    ~SpaceMission(){ 
    delete spaceship;
    cout<<"Spaceship Landed!"<<endl;
    delete spacesuit;
    cout<<"SpaceSuit taken Off!"<<endl;
    cout<<"Space Mission Done!"<<endl;
   }
private:
    SpaceFactory* factory;
    Spaceship* spaceship;
    SpaceSuit* spacesuit;
};
#endif // SPACEMISSION_H
