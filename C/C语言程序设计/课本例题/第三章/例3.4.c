#include<stdio.h>
#define PI 3.14159
int main ()
{
    double r;
    printf("Input r:");
    scanf("%lf",&r);
    printf("circumference=%f\n",2*PI*r);
    printf("area=%f\n",PI*r*r);
    return 0;
}