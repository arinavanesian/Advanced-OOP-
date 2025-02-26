#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    // TODO: Create setter methods for 'name' and 'age'
    void setName(const std::string& name){
        this->name = name;
    }
    void setAge(int age){
        this->age = age;
    }
    // TODO: Create getter methods for 'name' and 'age'
    std::string getName() const{
        return name;
    }
    int getAge(){
        return (age);
    }
    // TODO: Make 'name' and 'age' private
private:
    std::string name;
    int age;
};

int main() {
    Person person("Alice", 30);

    // TODO: Change the 'name' and 'age' attributes using the setter methods instead
    person.setName("Bob");
    person.setAge(25);

    // TODO: Print the 'name' and 'age' attributes using the getter methods instead
    std::cout << "Name: " << person.getName() << ", Age: " << person.getAge() << std::endl;

    return 0;
}
