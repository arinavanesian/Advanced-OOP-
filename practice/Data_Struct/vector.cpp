#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Vect{
public:
    Vect(int n);
    ~Vect();
int* data;
int size;        
};
Vect::Vect(int n) {
    size = n;
    data = new int[n];
}
Vect::~Vect(){
    delete[] data;
}
int main(int argc, char const *argv[])
{
    Vect a(100);
    Vect b=a;
    Vect c = a;
    cout<<"Ad: "<<&a;
    cout<<"Ad: "<<&b;
    cout<<"Ad: "<<&c;
    return 0;
}


