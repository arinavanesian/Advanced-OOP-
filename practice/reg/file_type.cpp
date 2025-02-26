#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstddef>
using std::string;
using namespace std;

// binary: Uses the prefix 0b 0b1010
// octal Uses the prefix 0  023
// decimal This is the default %d
// hexadecimal Uses the prefix 0x 0xFFF
// printf specifiers %x for hexa, %o octa, 

// 4bytes
// Float - single precision
//8bytes
// double - double prec.
//long double - extended 
int main()
{
    int n = 124;
    cout<<n<<endl;
    unsigned short a = 0b10101010; 
    printf("Unsigned Short: %hu\n", a);
    int b = 0123;
    printf("%d\n", b); 
    unsigned long long d = 0xFFFFFFFFFFFFFFFF; 
    printf("Unsigned Long Long %llu\n", d);
    int dec = 124;
    cout<<dec<<endl;
    unsigned short bin = 0b101; 
    printf("Unsigned Short: %hu\n", bin);
    int octal = 023;
    printf("%d\n", octal); 
    unsigned long long hexa = 0xFFF; 
    printf("Unsigned Long Long %llu\n", hexa);

// Getting the sizes of the variables

    int size_char = sizeof(char);
    printf("Char Size: %d\n", size_char);

    size_t size_c = sizeof(char);
    cout << size_c << endl;
    cout << typeid(size_c).name() << endl;	    
    // printf("Char Size: %zd\n", size_char);
// printf(1999)
// printf

    return 0;
}
