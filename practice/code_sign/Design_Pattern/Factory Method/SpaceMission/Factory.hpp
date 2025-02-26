#ifndef FACTORY_H
#define FACTORY_H

#include "Spaceship.hpp"
#include "Spacesuit.hpp"
using namespace std;
// TODO: Define an interface SpaceFactory with pure virtual functions createSpaceship() and ()
class SpaceFactory{
public:
    virtual ~SpaceFactory() = default;
    virtual Spaceship* createSpaceship() =0;
    virtual SpaceSuit* createSpaceSuit() = 0;
};
// TODO: Define NASAFactory class that inherits from SpaceFactory and implements createSpaceship() and createSpaceSuit()
class NASAFactory:public SpaceFactory{
public:
    Spaceship* createSpaceship() override{
        return new NASASpaceship();
    }
    SpaceSuit* createSpaceSuit() override{
        return new NASASpaceSuit();
    }
};
// TODO: Define SpaceXFactory class that inherits from SpaceFactory and implements createSpaceship() and createSpaceSuit()

class SpaceXFactory:public SpaceFactory{
public:
    Spaceship* createSpaceship() override{
        return new SpaceXSpaceship();
    }
    SpaceSuit* createSpaceSuit() override{
        return new SpaceXSpaceSuit();
    }
    
};
#endif // FACTORY_H
