#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
	virtual void makeSound() = 0;
	virtual ~Animal() = default;
	virtual int getLegs() const = 0;
protected:

//	Animal(){cout<<"Animal created!"<<endl;}
	int legs;
};

class Dog : public Animal{
public:
	Dog(int puppy){
	cout<<"Dog created!"<<endl;
	legs =4;
	this->puppy = puppy;
	}
	void makeSound() override{
	cout<<"Woof!"<<endl;
	}
	int getPuppy() {
	return this->puppy;
	}
	int getLegs() const override{
	return this->legs;
	}
private:
	int puppy;
};

class Cat:public Animal{
public:
	Cat(int kitten){
	       cout<<"Cat is created!"<<endl;	       
		legs = 4;
		this->kitten = kitten;
	}
	void makeSound() override{
	cout<<"Meow!"<<endl;
	}
	int getLegs() const override{
		return this->legs;
	}
private:
	int kitten;
};
class Zoo{
	public:
	Zoo(int size) {
        this->size = size;
        this->currentIndex = 0;
        this->cap = new Animal*[size](); // Dynamically allocate array of pointers
        cout << "Zoo capacity: " << this->size << endl;
    }

    ~Zoo() {
        delete[] cap; // Free allocated memory
    }

    int getSize() const {
        return this->size;
    }

    void addAnimals(Animal* animal) {
        if (currentIndex < size) {
            cap[currentIndex++] = animal;
        } else {
            cout << "Zoo is full!" << endl;
        }
    }
	Animal** getCap(){
		return this->cap;
	}
private:
    int size;
    int currentIndex;
    Animal** cap;
};
int main() {
    Animal* dog = new Dog{15};
    dog->makeSound();
    cout << "Number of legs: " << dog->getLegs() << endl;
    delete dog;

    Animal* cat = new Cat(3);
    cat->makeSound();
	Zoo* zoo = new Zoo(10);
	zoo->addAnimals(dog);
	int  n = zoo->getSize();
	for (size_t i = 0; i <n ; i++)
	{
		zoo.getCap()[i].makeSound();
	}
	
    delete cat;

    return 0;
}
