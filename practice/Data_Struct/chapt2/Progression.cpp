#include <iostream>
#include <string>

using namespace std;

class Progression
{
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

void Progression::printProgression(int n)
{
    cout << firstValue();
    for (int i = 2; i <= n; i++)
    { // Use int for loop counter
        cout << " " << nextValue();
    }
    cout << endl; // Add newline at the end
}

long Progression::firstValue()
{
    curr = first;
    return curr;
}

long Progression::nextValue()
{
    return ++curr;
}

class Arithmetic : public Progression
{
public:
    Arithmetic(long i= 1) : Progression(), inc(i) {}

protected:
    long nextValue() override; // Use override for clarity and to catch errors

private: // Changed to private for better encapsulation
    int inc;
};

long Arithmetic::nextValue()
{
    curr += inc; // Use += for conciseness
    return curr;
}

class Geometric : public Progression
{
public:
    Geometric(long b=1) : Progression(1), base(b) {}

protected:
    long nextValue() override;

private:
    long base; // Changed to long to handle potential overflow
};

long Geometric::nextValue()
{
    curr *= base;
    return curr;
}

class Fibonacci : public Progression
{
public:
    Fibonacci(long f=0, long s=1) : Progression(f), second(s), prev(second - first) {}

protected:
    long firstValue() override;
    long nextValue() override;

private:
    long second;
    long prev;
};

long Fibonacci::firstValue()
{
    curr = first;
    prev = second - first;
    return curr;
}

long Fibonacci::nextValue()
{
    long temp = prev;
    prev = curr;
    curr += temp;
    return curr;
}

int main()
{
    Progression *prog; // test Arithmetic
    cout << "Arithmetic progression with default increment:\n";
    prog = new Arithmetic(); 
    prog->printProgression(10);  
    cout << "Arithmetic progression with increment 5:\n"; 
    prog = new Arithmetic(5); 
    cout << "Geometric progression with default base:\n"; 
    prog = new Geometric(); 
    prog->printProgression(10);  
    cout << "Geometric progression with base 3:\n"; 
    prog = new Geometric(3); 
    prog->printProgression(10); // test FibonacciProgression  
    cout << "Fibonacci progression with default start values:\n"; 
    prog = new Fibonacci(); 
    prog->printProgression(10);  
    cout << "Fibonacci progression with start values 4 and 6:\n"; 
    prog = new Fibonacci(4, 6);
    prog->printProgression(10);
    return EXIT_SUCCESS; 