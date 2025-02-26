#include <iostream>
#include <cstdio>
#include <stdio.h>
using std::string;
using namespace std;

class Employee{
public:
    string Name;
    string Company;
    int Age;
Employee(string Name,string Company,int Age){
    this->Name  = Name;
    this->Company = Company;
    this->Age = Age;
}
public:
    void toString(){
        cout<<"Name:  " << Name << endl;
        cout<< "Company: "<<Company<<endl;
        cout<<"Age: "<<Age<<endl;
    }
};

int main()
{
    
    Employee e1 = Employee("Gero", "Ford", 50);
    e1.toString();
    return 0;
}
