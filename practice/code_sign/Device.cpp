#include <iostream>
#include <string>

// Define a base class Person with name and age attributes
class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Define a virtual display method to signify, that it can be overridden by derived classes
    virtual void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

private:
    std::string name;
    int age;
};

// Define a derived class Student with a major attribute
class Student : public Person {
public:
    Student(const std::string& name, int age, const std::string& major)
        : Person(name, age), major(major) {}

    // Override the display method to include the major attribute. Note that the 'override' keyword is optional but recommended for clarity.
    void display() override {
        Person::display();
        std::cout << "Major: " << major << std::endl;
    }

private:
    std::string major;
};

// Define a derived class Teacher with a subject attribute
class Teacher : public Person {
public:
    Teacher(const std::string& name, int age, const std::string& subject)
        : Person(name, age), subject(subject) {}

    // Override the display method to include the subject attribute
    void display() override {
        Person::display();
        std::cout << "Subject: " << subject << std::endl;
    }

private:
    std::string subject;
};

int main() {
    // Create instances of Student and Teacher using base class pointers
    Person* person1 = new Student("Alice", 30, "Computer Science");
    Person* person2 = new Teacher("Bob", 25, "Mathematics");

    // Call the display method on the base class pointers. The appropriate derived class method will be invoked.
    person1->display();
    person2->display();

    // Free the allocated memory to avoid memory leaks
    delete person1;
    delete person2;
    return 0;
}
