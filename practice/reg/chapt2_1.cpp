#include <iostream>
#include <cstdio>
using namespace std;

// 2-1. Create an enum class Operation that has values Add, Subtract, Multiply, and Divid
enum class Operation{
     Add, Subtract, Multiply, Divide
};

// 2-2. Create a struct Calculator. It should have a single constructor that takes an Operation
struct Calculator{
    Operation op;
    Calculator(Operation op){
        this->op = op;
    }
//2-3. Create a method on Calculator called int calculate(int a, int b).  Upon invocation, this method should perform addition, subtraction, multiplication, or division based on its constructor argument and return the result.
   int calculate(int a, int b){
       switch (op)
    {
    case Operation::Add:{
        cout<<a+b<<endl;
    }
        break;
    case Operation::Multiply:{
            cout<<a*b<<endl;

    }
        break;
    case Operation::Divide:{
        cout<<a/b<<endl;
    }
        break;
    case Operation::Subtract:{
        cout<<a-b<<endl;
    }
        break;
    }
    return 0;
    }
};


int main(int argc, char const *argv[])
{

    Operation op = Operation::Add;
    float a{4.2};
    float b{5.2};
    Calculator calc{Operation::Subtract};
    calc.calculate(7, 3);    
    return 0;
}
