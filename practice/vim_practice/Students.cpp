#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Student{
public:
	Student(const string& name, int age): name(name), age(age){}

	const string& getName() const{
	return this->name;
	}
	int getAge() const{
	return this-> age;
	
	}
private:
	string& name;
	int age;
};

class ClassRoom{
public:
private:
	const int CAPACITY = 10;
	Student* room[CAPACITY];
};
int main(){


return 0;
}
