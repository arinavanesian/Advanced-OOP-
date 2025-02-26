#include <iostream>
#include <cstring> 
using namespace std;

class Molecule {
private:
    int charge;
    char name[30];
    bool isCharged;
    float weight;

public:
   
    Molecule() : charge(0), isCharged(false), weight(0.0f) {
        name[0] = '\0'; 
    }

    
    Molecule(const char* name, int charge, float weight, bool isCharged) {
        strncpy(this->name, name, 29);
        this->name[29] = '\0'; 
        this->charge = charge;
        this->weight = weight;
        this->isCharged = isCharged;
    }


    const char* get_name() const {
        return name;
    }

    
    void set_name(const char* name) {
        strncpy(this->name, name, 29);
        this->name[29] = '\0';
    }

    
    int get_charge() const {
        return charge;
    }

   
    void set_charge(int charge) {
        this->charge = charge;
    }

    float get_weight() const {
        return weight;
    }

    void set_weight(float weight) {
        this->weight = weight;
    }

    
    bool get_isCharged() const {
        return isCharged;
    }

    
    void set_isCharged(bool isCharged) {
        this->isCharged = isCharged;
    }
};

int main() {
    
    Molecule water("Water", 0, 18.015f, false);
    Molecule oxygen("Oxygen", 0, 15.999f, false);
    Molecule sodiumChloride; 

    sodiumChloride.set_name("Sodium Chloride");
    sodiumChloride.set_charge(0);
    sodiumChloride.set_weight(58.44f);
    sodiumChloride.set_isCharged(false);

    cout << "Molecule 1: " << water.get_name() << ", Charge: " << water.get_charge()
         << ", Weight: " << water.get_weight() << ", Charged: " << (water.get_isCharged() ? "Yes" : "No") << endl;

    cout << "Molecule 2: " << oxygen.get_name() << ", Charge: " << oxygen.get_charge()
         << ", Weight: " << oxygen.get_weight() << ", Charged: " << (oxygen.get_isCharged() ? "Yes" : "No") << endl;

    cout << "Molecule 3: " << sodiumChloride.get_name() << ", Charge: " << sodiumChloride.get_charge()
         << ", Weight: " << sodiumChloride.get_weight() << ", Charged: " << (sodiumChloride.get_isCharged() ? "Yes" : "No") << endl;

    return 0;
}