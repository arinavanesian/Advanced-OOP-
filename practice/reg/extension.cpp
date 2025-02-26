#include <iostream>
using namespace std;

double power(double a, int n);
int main(){
  int exponent=18;
  double base=5.3;
  double value;
 
  value = power(base,exponent);
  cout.precision(12);
  cout << value << endl;
  base = 2;
  exponent = 4;
  value = power(base, exponent);
  cout<<value<<endl;
  return 0;
}

double power(double a, int n)
{
  int i;//0
  double val=a; //2
 
  for(i=1; i < n; i++)
    val *= a;//4 8 16
 
  return val;
}