#include "SpaceMission.hpp"
#include <iostream>
using namespace std;
int main() {
    // TODO: Create a pointer of type SpaceFactory and set it to nullptr
    SpaceFactory* factory = nullptr;
     // TODO: Create a string variable named agencyType and set it to "NASA" (change to "SpaceX" for SpaceX setup)
    string agencyType = "NASA";
    // TODO: Depending on the value of agencyType, initialize the factory pointer to NASAFactory or SpaceXFactory
    if (agencyType == "NASA") {
        factory = new NASAFactory();
    } else if (agencyType == "SpaceX") {
        factory = new SpaceXFactory();
    }

    
    // TODO: If factory is not nullptr, create a SpaceMission object using factory, call its prepare() method, and delete objects
    if(factory){
        SpaceMission* mission = new SpaceMission(factory);
        mission->prepare();
    delete factory;
    delete mission;
    }
    // TODO: If factory is nullptr, print "Unknown agency type."
    else
        cout << "Unknown agency type." << endl;
    return 0;
   
}
