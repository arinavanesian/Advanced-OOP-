#include <iostream>
#include <cstdio>
using namespace std;

void junk(&i);
int main(){

	 int i=1;
 
  cout << "in main, i= " << i << endl;
  junk(i);
  cout << "in main, i= " << i << endl;
 
  return 0;
}
 
void junk(int &i)
{
  i=2;
  cout << "in junk, i= " << i << endl;
}
