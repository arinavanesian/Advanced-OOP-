#include <iostream>
#include <cstdint>
using namespace std;

struct PodStruct{
uint64_t a;
char word [32];
bool c;
};

class Molecule{
int charge;
char name[30];
bool isCharged;
float weight;
Molecule(){};
Molecule(int name, int charge, float weight, bool isCharged){
    this->name = name;
    this->charge= charge;
    this->weight = weight;
    this->isCharged = isCharged;
}
public:
char[] get_name(){
    return name;
}
char[] get_name(){
    return name;
}
};


int main(){
PodStruct str1{}; // ={}
str1={34, "Done!"};
PodStruct str2 = {43, "Can make it!", true};    
cout << str1.a << endl;
cout << typeid(str1).name() << endl; //9PodStruct
cout <<typeid(str2).name() << endl; //9PodStruct

//Creating a Molecule object here
Molecule m1{};
m1.
cout<< "Molecule Name: " <<
}
