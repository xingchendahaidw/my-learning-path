#include<stdio.h>
#define PI 3.14159
int main()
{
    double r,area,volume;
    scanf("%lf",&r);
    area=4*PI*r*r;
    volume=4.0/3*PI*r*r*r;
    printf("球的表面积：%.4lf",area);
    printf("球的体积：%.4lf",volume);
    return 0;
}