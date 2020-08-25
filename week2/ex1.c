#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {    

    int integer1 = INT_MAX;
    float float1 = FLT_MAX;
    double double1 = DBL_MAX;
    
    printf("Size of the integer:\n%li\nValue of the max integer:\n%i\n",sizeof(integer1),integer1);
    printf("Size of the float:\n%li\nValue of the max float:\n%f\n",sizeof(float1),float1);
    printf("Size of the double:\n%li\nValue of the max double:\n%f\n",sizeof(double1),double1);
    return 0;
}