#include<stdio.h>

int main ()
{
    const double PI=3.14159;
    double r;
    printf("Input r:");
    scanf("%lf",&r);
    printf("circumference=%f\n",2*PI*r);
    printf("area=%f\n",PI*r*r);
    return 0;
}