#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int int_a[] = {2, 3, 4, 55};
 //   printf("Int Array:"); //Int Array: -9744
//    printf("2nd Array element: %d\n", int_a[1]); //2nd Array element: 3
 //  int_a[3] = 33;
//    printf("4th Array element: %d\n", int_a[3]); //2nd Array element: 3
//Range-based iteration
    int maxim = 0;
    for(int a:int_a)
	if(maxim < a) maxim = a;
    printf("Max: %d", maxim);
    cout << "\n" << endl;
    //Number of elements
    size_t n_el = sizeof(int_a)/sizeof(int);
    cout << n_el<< endl;
    return 0;
}
