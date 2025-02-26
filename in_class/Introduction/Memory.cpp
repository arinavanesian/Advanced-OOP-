#include <iostream>
#include <cstdio>  // For printf
#include <cstring> // For memcpy (alternative to bit_cast)

int main() {
    int n = 1;
    //format only recognizes void pointers
    printf("\nInt value n = %d\n", n);
    printf("Int address of n = %p is a reference to the existing int\n", static_cast<void*>(&n));
    printf("Next int value = %d\n", n + 1);
    printf("Next int address = %p is not a reference, it is an int pointer\n", (&n + 1));
    printf("Content of the reference = %d is again n\n", *&n);
    printf("Content of the next pointer = %d is a default garbage\n", *(&n + 1)); //since not reserved initially

    unsigned char* p = reinterpret_cast<unsigned char*>(&n);
    printf("\nAddress: %p\n", static_cast<void*>(p)); //1 shouldn't this be an address
    printf("Byte 0: %d\n", *p); //0
    printf("Byte 1: %d\n", static_cast<int>(*(p + 1))); //0
    printf("Byte 2: %d\n", static_cast<int>(*(p + 2))); //0
    printf("Byte 3: %d\n", static_cast<int>(*(p + 3))); //0

    float x = n;
    printf("\nFloat value x = %f\n", x);
    printf("Float address of x = %p is a reference to the existing float\n", static_cast<void*>(&x));
    printf("Next float value = %f\n", x + 1);
    printf("Next float address = %p is not a reference, it is a float pointer\n", static_cast<void*>(&x + 1));
    printf("Content of the reference = %f is again x\n", *&x);
    printf("Content of the next pointer = %f is a default garbage\n", *(&x + 1));

    p = reinterpret_cast<unsigned char*>(&x);
    printf("\nAddress: %p\n", static_cast<void*>(p));
    for (; p < reinterpret_cast<unsigned char*>(&x + 1); p++) {
        printf("Byte %ld: %d\n", p - reinterpret_cast<unsigned char*>(&x), static_cast<int>(*p));
    }

    double y = n;
    printf("\nDouble value y = %lf\n", y);
    printf("Double address of y = %p is a reference to the existing double\n", static_cast<void*>(&y));
    printf("Next double value = %lf\n", y + 1);
    printf("Next double address = %p is not a reference, it is a double pointer\n", static_cast<void*>(&y + 1));
    printf("Content of the reference = %lf is again y\n", *&y);
    printf("Content of the next pointer = %lf is a default garbage\n", *(&y + 1)); //not reserved by the program initially
//try bool type casting
    p = reinterpret_cast<unsigned char*>(&y);
    printf("\nAddress: %p\n", static_cast<void*>(p));
    for (; p < reinterpret_cast<unsigned char*>(&y + 1); p++) {
        printf("Byte %ld: %d\n", p - reinterpret_cast<unsigned char*>(&y), static_cast<int>(*p));
    }

    return 0;
}