#include <iostream>
#include <cstdio>

int main(int argc, char const *argv[])
{
    float b{5};
    float a{4};
    int narrow_result(b/a);
    printf("This is a float %lf\n", a); //4.000
    printf("This is a long long \n",b);
    printf("This is a float %d\n", narrow_result); //1
    return 0;
}
