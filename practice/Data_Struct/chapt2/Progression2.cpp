#include <iostream>
#include <string>
using namespace std;

class Progression {
public:
    Progression(long f = 0) : first(f), curr(f) {}
    virtual ~Progression() = default; // Modern C++ way to define a virtual destructor

    void printProgression(int n);

protected:
    virtual long firstValue();
    virtual long nextValue();

protected:
    long first;
    long curr;
};

void Progression::printProgression(int n) {
    cout << firstValue();
    for (int i = 2; i <= n; i++) { // Use int for loop counter
        cout << " " << nextValue();
    }
    cout << endl; // Add newline at the end
}

long Progression::firstValue() {
    curr = first;
    return curr;
}

long Progression::nextValue() {
    return ++curr;
}

class Arithmetic : public Progression {
public:
    Arithmetic(long i) : Progression(), inc(i) {}

protected:
    long nextValue() override; // Use override for clarity and to catch errors

private: // Changed to private for better encapsulation
    int inc;
};

long Arithmetic::nextValue() {
    curr += inc; // Use += for conciseness
    return curr;
}

class Geometric : public Progression {
public:
    Geometric(long b) : Progression(1), base(b) {}

protected:
    long nextValue() override;

private:
    long base; // Changed to long to handle potential overflow
};

long Geometric::nextValue() {
    curr *= base;
    return curr;
}

class Fibonacci : public Progression {
public:
    Fibonacci(long f, long s) : Progression(f), second(s), prev(second - first) {}

protected:
    long firstValue() override;
    long nextValue() override;

private:
    long second;
    long prev;
};

long Fibonacci::firstValue() {
    curr = first; //3 4
    prev = second - first;//4-3
    return curr;//3
}

long Fibonacci::nextValue() {
    long temp = prev;
    prev = curr;
    curr += temp;
    return curr;
}

int main() { // Removed unnecessary arguments
    Arithmetic a(2);
    cout << "Arithmetic Progression: ";
    a.printProgression(5); // Example usage

    Geometric g(3);
    cout << "Geometric Progression: ";
    g.printProgression(5); // Example usage

    Fibonacci f(3, 4);
    cout << "Fibonacci Progression: ";
    f.printProgression(10);  // Example usage

    return 0;
}